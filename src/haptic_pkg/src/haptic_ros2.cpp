#include "haptic_pkg/haptic_ros2.h"

using namespace std::chrono_literals;

HapticRos::HapticRos() : Node("haptic_node"), is_running_(false)
{
    hap_device_ = std::make_unique<HapticEngine>();
}

HapticRos::~HapticRos()
{
    if (is_running_.load())
    {
        stop();
    }
}

bool HapticRos::setup()
{
    if (!hap_device_->setup())
    {
        RCLCPP_ERROR(this->get_logger(), "Failed to setup hap_device");
        return false;
    }

    // Create publisher and subscriber
    data_pub_ = this->create_publisher<haptic_pkg::msg::ReadData>("hap/motion_data", 1000);
    force_sub_ = this->create_subscription<haptic_pkg::msg::WriteData>(
        "/hap/force_data", 10,
        std::bind(&HapticRos::forceCallback_, this, std::placeholders::_1));

    RCLCPP_INFO(this->get_logger(), "Setup complete");
    return true;
}

bool HapticRos::start()
{
    if (!hap_device_->start())
    {
        RCLCPP_ERROR(this->get_logger(), "Failed to start hap_device");
        return false;
    }

    if (is_running_.load())
    {
        RCLCPP_WARN(this->get_logger(), "Already running");
        return false;
    }

    is_running_.store(true);

    force_th_ = std::thread(&HapticRos::forceWork_, this);
    read_th_ = std::thread(&HapticRos::dataWork_, this);
    device_th_ = std::thread(&HapticRos::deviceWork_, this);

    RCLCPP_INFO(this->get_logger(), "Started");
    return true;
}

bool HapticRos::stop()
{
    is_running_.store(false);

    if (force_th_.joinable())
    {
        force_th_.join();
    }
    if (read_th_.joinable())
    {
        read_th_.join();
    }
    if (device_th_.joinable())
    {
        device_th_.join();
    }

    RCLCPP_INFO(this->get_logger(), "Stop called");
    return true;
}

bool HapticRos::isRunning() const
{
    return is_running_.load();
}

void HapticRos::forceWork_()
{
    rclcpp::Rate rate(HAPTIC_RATE);

    while (rclcpp::ok() && is_running_.load())
    {
        rclcpp::spin_some(this->get_node_base_interface());
        rate.sleep();
    }
}

void HapticRos::dataWork_()
{
    rclcpp::Rate rate(PUBLISH_RATE);

    while (rclcpp::ok() && is_running_.load())
    {
        haptic_pkg::msg::ReadData read_tmp;
        {
            std::lock_guard<std::mutex> lock(read_mut_);
            read_tmp = read_data_;
        }
        data_pub_->publish(read_tmp);
        rate.sleep();
    }
}

void HapticRos::forceCallback_(const haptic_pkg::msg::WriteData::SharedPtr msg)
{
    haptic_pkg::msg::WriteData write_tmp;

    if (msg != nullptr)
    {
        write_tmp = *msg;
        
        std::lock_guard<std::mutex> lock(write_mut_);
        write_data_ = write_tmp;
    }
}

void HapticRos::deviceWork_()
{
    // Wait for is_running_ to be true
    while (!is_running_.load())
    {
        std::this_thread::yield();
    }

    while (rclcpp::ok() && is_running_.load())
    {
        AddMotion::HapMotionData motion;
        AddMotion::HapForceData force;

        hap_device_->work();
        hap_device_->readMotionData(motion);

        // Update read_data_
        haptic_pkg::msg::ReadData read_tmp;
        read_tmp.enable_button = motion.joy1;
        read_tmp.grab_button = motion.joy2;

        for (int i = 0; i < 6; ++i)
        {
            read_tmp.platform_velocity[i] = motion.data[i];
            read_tmp.platform_position[i] = motion.pos_data[i];
        }

        {
            std::lock_guard<std::mutex> lock(read_mut_);
            read_data_ = read_tmp;
        }

        // Get force data
        {
            std::lock_guard<std::mutex> lock(write_mut_);
            // RCLCPP_INFO(this->get_logger(), "device work");
            for (int i = 0; i < 6; ++i)
            {

                force.force[i] = write_data_.force_data[i];
                //RCLCPP_INFO(this->get_logger(), "force : %f", force.force[i]);
            }
        }

        hap_device_->writeForceData(force);
    }
}
