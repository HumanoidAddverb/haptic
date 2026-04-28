/**
 * @file state_interface.h
 * @author Rajesh Kumar (rajesh.kumar01@addverb.com)
 * @brief Implementation of the state interface 
 * @version 0.1
 * @date 2023-07-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef STATE_INTERFACE_H_
#define STATE_INTERFACE_H_

#include <memory>
#include "haptic_actions.h"
#include "data_manager.h"

class HapticContext;

/**
 * @brief Interface for the state class 
 * for the different states which the 
 * haptic device can assume 
 * 
 */
class StateInterface
{

    public : 

    virtual ~StateInterface() {}; 

    virtual bool performAction(HappActions, HapticContext *) = 0;

    virtual bool run() = 0; 

    virtual bool setup(HapticContext *ptr) = 0; 

};

#endif 
