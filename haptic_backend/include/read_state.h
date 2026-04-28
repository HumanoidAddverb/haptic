
/**
 * @file read_state.h
 * @author Rajesh Kumar (rajesh.kumar01@addverb.com)
 * @brief Description of the read state 
 * @version 0.1
 * @date 2023-07-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef READ_STATE_H_
#define READ_STATE_H_

#include "state_baseline.h"

/**
 * @brief Base state implementation : 
 * the place where the haptic device 
 * is originally placed 
 * 
 */
class ReadState : public StateBaseline 
{

    public :

    inline ReadState() {
        name_ = "Read State";
    };

    virtual inline ~ReadState() {};

    bool run() override; 


    private :

    bool handleStart_() override; 

    bool specializedSetup_() override; 



};

#endif 