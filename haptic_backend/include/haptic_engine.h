/**
 * @file haptic_engine.h
 * @author Rajesh Kumar (rajesh.kumar01@addverb.com)
 * @brief Concrete implementation of a haptic engine; concurrently 
 * has all the elements of and a run implementation of the actual robot; 
 * the idea is to abstract out the different elements 
 * @version 0.1
 * @date 2023-07-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef HAPTIC_ENGINE_H_
#define HAPTIC_ENGINE_H_

#include "haptic_engine_interface.h"
#include "logger_factory.h"
#include "lower_level_interface.h"
#include "lower_level_factory.h"
#include "safety_impl.h"
#include "haptic_utility.h"
#include "control_context_interface.h"
#include "engine_config.h"
#include "safety_interface.h"
#include "haptic_builder_factory.h"
#include "haptic_builder_interface.h"
#include "control_context.h"
#include "kd_impl.h"

/**
 * @brief Development of the haptic engine : incorporates all 
 * the elements required for the robot run within a while loop 
 * 
 */
class HapticEngine : public HapticEngineInterface
{

    public : 

    // create a haptic engine configuration : no parameters for the constructor 
    // assuming the parameters will be read off a json always 
    HapticEngine() {}; 

    // destroy the object 
    ~HapticEngine() {stop();}; 

    // setup and initialiae all the pointers 
    bool setup();

    // read the most recent motion data which the robot has written 
    // the system should return true only when the robot is actually running 
    // and not in an error 
    bool readMotionData(AddMotion::HapMotionData &) const; 

    // write the force data 
    bool writeForceData(AddMotion::HapForceData ) ; 

    // poll the current status of the robot 
    AddMotion::StatusWord pollStatus() const; 

    // start the robot : basically starts a read - write thread; there is no 
    // read only status for haptic engine : it starts and works 
    bool start(); 

    // stop the device 
    void stop(); 

    // just read from the device 
    bool read(); 

    // main working implementation 
    bool work(); 


    private :

    // pointer to the lower level object 
    std::unique_ptr<LowerLevelInterface> ll_ptr_;

    // pointer to the controller 
    std::unique_ptr<ControlContextInterface> control_context_; 

    // safety implementation 
    std::unique_ptr<SafetyInterface> safety_;

    // utility class interface : contains stuff which controller or safety can use 
    std::unique_ptr<UtilityClassInterface> utility_ptr_; 

    // pointer to the interface to kinematics module 
    std::unique_ptr<KDInterface> kd_; 

    // pointer to the logger implementation 
    LoggingInterface* log_ptr_;

    // status of the engine 
    AddMotion::StatusWord status_;

    // device data combining a lot of memebr containers 
    AddMotion::DeviceData device_data_;

    // control output required to sent to the lower level 
    AddMotion::ControlOutput control_; 

    // data corresponding to the initialization 
    AddMotion::InitializationConfig init_config_;

    // thread to perform the read write 
    std::thread worker_; 

    // thread to check whether the robot is working or not 
    std::atomic<bool> robot_working_; 

    // build the kinematics module for the robot
    bool buildKinematics_(); 

    // function which has most of the loop
    void work_();

};


#endif 