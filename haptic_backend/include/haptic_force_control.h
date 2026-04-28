/**
 * @file haptic_force_control.h
 * @author Rajesh Kumar (rajesh.kumar01@addverb.com)
 * @brief Haptic Force Control 
 * @version 0.1
 * @date 2023-07-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef HAPTIC_FORCE_CONTROL_H_
#define HAPTIC_FORCE_CONTROL_H_

// length for mv
#define AVG_LENGTH 100


#include "haptic_control_interface.h"
#include "utility_class_interface.h"
#include "kd_interface.h"
#include "haptic_utility.h"
#include "moving_average.h"
#include "data_manager.h"
// #include "data_handler.h"
#include <memory>
#include <thread>

/**
 * @brief Synthesis of the haptic force control 
 * 
 */
class HapticForceControl : public HapticControlInterface
{

    public : 

    inline HapticForceControl() {};

    inline ~HapticForceControl() {};

    bool setup() ;

    bool setData(const AddMotion::DeviceData &data) ;

    bool doControl(std::unique_ptr<UtilityClassInterface> &inp); 

    bool getOutput( AddMotion::ControlOutput &out); 

    private : 

    // precontrol data which the utility can update 
    AddMotion::PreControlData pre_data_; 
    
    // temporary structure for input output
    AddMotion::PreControlData tmp_;

    // object to the input data 
    AddMotion::DeviceData data_;

    // setup the control output 
    AddMotion::ControlOutput output_; 

    // moving average 
    std::unique_ptr<MovingAverage<Eigen::VectorXd>> filter_; 



};

#endif 