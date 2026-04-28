/**
 * @file haptic_context.h
 * @author Rajesh Kumar (rajesh.kumar01@addverb.com)
 * @brief Haptic Context : 
 * @version 0.1
 * @date 2023-07-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef HAPTIC_CONTEXT_H_
#define HAPTIC_CONTEXT_H_


#include <memory>

#include "state_interface.h"
#include "haptic_engine_interface.h"
#include "haptic_actions.h"
#include "haptic_engine.h"
#include "data_manager.h"



/**
 * @brief Haptic Context class : to incorporate 
 * the impending state machine implementations
 * 
 */
class HapticContext {
  public : 
    inline HapticContext() {};
    inline ~HapticContext() {
      hap_->stop(); 
    }; 

    bool setup(); 
    bool transitionTo(std::unique_ptr<StateInterface> &state); 
    bool performAction(HappActions);
    bool performTask(HappEngineTasks); 
    bool run(); 

  private :
    // pointer to the states 
    std::unique_ptr<StateInterface> state_; 
    // pointer to the haptic engine 
    std::unique_ptr<HapticEngineInterface> hap_; 
    // implementation to pause the system 
    bool pause_();
    // implementation to read from the system 
    bool read_(); 
    // implementation to write to the system
    bool write_();  
    // implementation to stop the system 
    bool stop_();
    // start the lower level comm 
    bool start_();
};

#endif 