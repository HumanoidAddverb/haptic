/**
 * @file base_state.h
 * @author Rajesh Kumar (rajesh.kumar01@addverb.com)
 * @brief Description of the base state 
 * @version 0.1
 * @date 2023-07-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef BASE_STATE_H_
#define BASE_STATE_H_

#include "state_baseline.h"
#include "read_state.h"

/**
 * @brief Base state implementation : 
 * the place where the haptic device 
 * is originally placed 
 * 
 */
class BaseState : public StateBaseline 
{

    public :

    inline BaseState() {
        name_ = "Base State";
    };

    virtual inline ~BaseState() {};

    bool run() override;

    protected :

    bool handleStart_() override; 

    bool specializedSetup_() override; 

};

#endif 