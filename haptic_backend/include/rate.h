/**
 * @file rate.h
 * @author Rajesh Kumar (rajesh.kumar01@addverb.com)
 * @brief Implementation of the rate class :
 * to ensure communication at max the specified 
 * rate; sleep implementation only
 * @version 0.1
 * @date 2023-07-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef RATE_H_
#define RATE_H_

#include <unistd.h>
#include "timer.h"
#include <thread>

/**
 * @brief implement the rate at which the system sleeps 
 * 
 */
class Rate
{

    public : 

    // Rate consructor : set the frequency container to the passed frequence
    // set local container of the previous time to be equal to the prev_time_
    inline Rate(int freq) : freq_(freq), cycle_sleep_time_(1/freq_) {
        tm_.timeReset();
        prev_time_ = tm_.getCurTime();
    };

    // destructor 
    inline ~Rate() {};

    void sleepThread();

    void sleepExe();

    private :

    ///@brief  frequency for Rate implementation
    int freq_; 

    ///@brief previous time local version
    double prev_time_; 

    ///@brief duration for sleeping time
    double cycle_sleep_time_;

    /// @brief Timer 
    Timer tm_;

};

#endif 