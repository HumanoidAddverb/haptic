/**
 * @file hap_control_interface.h
 * @author Rajesh Kumar (rajesh.kumar01@addverb.com)
 * @brief Haptic Control strategy 
 * @version 0.1
 * @date 2023-07-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef HAP_CONTROL_INTERFACE_H_
#define HAP_CONTROL_INTERFACE_H_

#include "read_write.h"
#include "utility_class_interface.h"
#include "control_error_codes.h"

/**
 * @brief Control interface to control 
 * the haptic device 
 * 
 */
class HapticControlInterface 
{
    public :

    virtual ~HapticControlInterface() {}; 

    virtual bool setup() = 0;

    virtual bool setData(const AddMotion::DeviceData &data) = 0;

    virtual bool doControl(std::unique_ptr<UtilityClassInterface> &inp) = 0; 

    virtual bool getOutput(AddMotion::ControlOutput &out) = 0; 

};

#endif 