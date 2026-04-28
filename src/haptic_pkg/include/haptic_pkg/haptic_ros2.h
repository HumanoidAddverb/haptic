#ifndef HAPTIC_ROS_H
#define HAPTIC_ROS_H

#include <memory>
#include <thread>
#include <mutex>
#include <atomic>
#include <rclcpp/rclcpp.hpp>

#include "haptic_pkg/msg/read_data.hpp"
#include "haptic_pkg/msg/write_data.hpp"
#include "haptic_engine.h"
#include "read_write.h"
#define PUBLISH_RATE 1000
#define HAPTIC_RATE 1000

class HapticRos : public rclcpp::Node {
public:
    HapticRos();
    ~HapticRos();

    bool setup();
    bool start();
    bool stop();
    bool isRunning() const; 

private:
    std::unique_ptr<HapticEngine> hap_device_;

    haptic_pkg::msg::ReadData read_data_;
    haptic_pkg::msg::WriteData write_data_;

    std::mutex mut_;
    std::mutex read_mut_;
    std::mutex write_mut_;

    std::thread force_th_;
    std::thread read_th_;
    std::thread device_th_;

    std::atomic<bool> is_running_;

    rclcpp::Publisher<haptic_pkg::msg::ReadData>::SharedPtr data_pub_;
    rclcpp::Subscription<haptic_pkg::msg::WriteData>::SharedPtr force_sub_;

    void forceCallback_(const haptic_pkg::msg::WriteData::SharedPtr msg);
    void forceWork_();
    void dataWork_();
    void deviceWork_();
};

#endif // HAPTIC_ROS_HPP
