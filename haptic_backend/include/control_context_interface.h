/**
 * @file control_context_interface.h
 * @author Rajesh Kumar (rajesh.kumar01@addverb.com)
 * @brief Control Context interface to change the 
 * type of controller if required 
 * @version 0.1
 * @date 2023-07-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef CONTROL_CONTEXT_INTERFACE_H_
#define CONTROL_CONTEXT_INTERFACE_H_

#include "read_write.h"
#include "engine_config.h"
#include "utility_class_interface.h"
#include "control_error_codes.h"
#include "error_manager.h"


/**
 * @brief Control Context to decide the type 
 * of controller to tbe used; to implement 
 * run time polymorphism 
 * 
 */
class ControlContextInterface
{

    public : 

    virtual ~ControlContextInterface() {};

    virtual bool selectControllerType(ControllerType type) = 0; 

    virtual bool setData(AddMotion::DeviceData data) = 0;

    virtual bool doControl(std::unique_ptr<UtilityClassInterface> &inp) = 0; 

    virtual bool getOutput(AddMotion::ControlOutput &out) = 0; 

};


#endif 