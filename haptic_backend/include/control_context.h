/**
 * @file control_context.h
 * @author Rajesh Kumar (rajesh.kumar01@addverb.com)
 * @brief Class controls the context of the type of controller 
 * required for the haptic device; useful when the controller 
 * if and when required to changed at runtime 
 * takes in the  
 * @version 0.1
 * @date 2023-07-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef CONTROL_CONTEXT_H_
#define CONTROL_CONTEXT_H_

#include "control_context_interface.h"
#include "haptic_control_interface.h"
#include "haptic_force_control.h"

#include <memory>

/**
 * @brief Concrete implementation of the class 
 * controlling the type of controller at run time 
 * currently only force control 
 * 
 */
class ControlContext : public ControlContextInterface 
{

    public :

    inline ControlContext() {
        control_ = nullptr; 
    };

    inline ~ControlContext() {};

    bool selectControllerType(ControllerType type);

    bool setData(AddMotion::DeviceData data); 

    bool doControl(std::unique_ptr<UtilityClassInterface> &inp); 

    bool getOutput(AddMotion::ControlOutput &out); 

    private :

    // container holding the complete data for the control 
    // context passes it to the local controller 
    AddMotion::DeviceData data_; 

    // pointer to the controller selected 
    std::unique_ptr<HapticControlInterface> control_; 






    
};

#endif 