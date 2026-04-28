/**
 * @file write_state.h
 * @author Rajesh Kumar (rajesh.kumar01@addverb.com)
 * @brief Description of the write state 
 * @version 0.1
 * @date 2023-07-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef WRITE_STATE_H_
#define WRITE_STATE_H_

#include "state_baseline.h"
#include "haptic_context.h"

/**
 * @brief Base state implementation : 
 * the place where the haptic device 
 * is originally placed 
 * 
 */
class WriteState : public StateBaseline 
{

    public :

    inline WriteState() {
        name_ = "Write State";
    };

    virtual inline ~WriteState() {};

    bool run(); 

    private :



};

#endif 