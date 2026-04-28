/**
 * @file safety_interface.h
 * @author Rajesh Kumar (rajesh.kumar01@addverb.com)
 * @brief Implementation of the read and write safety 
 * with the peak torque values and the peak input velocities 
 * to be added 
 * @version 0.1
 * @date 2023-07-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#ifndef SAFETY_INTERFACE_H_
#define SAFETY_INTERFACE_H_

#include "utility_class_interface.h"
#include "read_write.h"
/**
 * @brief Class to implement the read 
 * and the write safety modules; kinematics will 
 * be available via utility 
 * 
 */
class SafetyInterface
{

    public : 

    virtual ~SafetyInterface() {};

    virtual bool setup() = 0; 

    virtual bool performReadSafety(std::unique_ptr<UtilityClassInterface> &ptr, AddMotion::ActuatorData &data) = 0; 

    virtual bool performWriteSafety(std::unique_ptr<UtilityClassInterface> &ptr, AddMotion::ControlOutput &data)  = 0; 

};

#endif 