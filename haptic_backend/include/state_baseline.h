/**
 * @file state_baseline.h
 * @author Rajesh Kumar (rajesh.kumar01@addverb.com)
 * @brief State baseline implementation 
 * comprises of all the functions and the 
 * sub modules which the states might require or might 
 * have in common 
 * @version 0.1
 * @date 2023-07-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef STATE_BASELINE_H_
#define STATE_BASELINE_H_

#include "state_interface.h"
#include "haptic_actions.h"
#include "logger_headers.h"

/**
 * @brief State baseline implementation 
 * 
 */
class StateBaseline : public StateInterface
{

    public :

    inline StateBaseline() {
        name_ = "baseline"; 
    };

    virtual inline ~StateBaseline() {}; 

    virtual bool setup(HapticContext *); 

    virtual bool performAction(HappActions, HapticContext *); 

    virtual bool run();

    protected :

    // start action implementation for the baseline implementation 
    virtual bool handleStart_(); 

    // stop action implementation for the baseline implementation 
    virtual bool handleStop_(); 

    // error action corresponding to the baseline implementation
    virtual bool handleError_();

    // pause action handling 
    virtual bool handlePause_(); 

    // specialized setup entity which each of the 
    // state implementations will differ 
    virtual bool specializedSetup_();

    // setup the logger 
    virtual void setlog_();  

    // pointer to the temporary state of the device 
    std::unique_ptr<StateInterface> tmp_state_;

    // pointer to the haptic context 
    HapticContext *context_ptr_; 

    // logger to log the state transitions 
    LoggingInterface *log_;

    // name of the state 
    std::string name_; 


};


#endif 

