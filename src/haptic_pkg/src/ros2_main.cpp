#include "haptic_pkg/haptic_ros2.h"
#include "rclcpp/rclcpp.hpp"

int main(int argc, char** argv)
{
    // Initialize ROS2
    rclcpp::init(argc, argv);

    // Create the HapticRos node
    auto haptic_node = std::make_shared<HapticRos>();

    if(!haptic_node->setup())
    {
        RCLCPP_ERROR(rclcpp::get_logger("haptic_main"), "Setup failed");
        rclcpp::shutdown();
        return -1;
    }

    if(!haptic_node->start())
    {
        RCLCPP_ERROR(rclcpp::get_logger("haptic_main"), "Start failed");
        rclcpp::shutdown();
        return -1;
    }

    // Wait while node runs
    rclcpp::Rate loop_rate(10);
    while (rclcpp::ok() && haptic_node->isRunning()) {
        loop_rate.sleep();
    }

    haptic_node->stop();

    // Shutdown ROS2
    rclcpp::shutdown();

    return 0;
}