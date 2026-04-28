/**
 * @file error_state.h
 * @author Rajesh Kumar (rajesh.kumar01@addverb,com)
 * @brief Description of the error state 
 * @version 0.1
 * @date 2023-07-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#ifndef ERROR_STATE_H_
#define ERROR_STATE_H_

#include "state_baseline.h"

/**
 * @brief Description of the 
 * error state implementation 
 * for the haptic device 
 * 
 */
class ErrorState : public StateBaseline
{

    public : 

    inline ErrorState() {
        name_ = "Error state";
    };

    virtual inline ~ErrorState() {};

    bool run() override;

    private : 

    bool handleError_() override;  



};

#endif 