/**
 * @file Timer.h
 * @author Rajesh Kumar (rajesh.kumar01@addverb.com)
 * @brief Get the current time 
 * @version 0.1
 * @date 2023-09-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef TIMER_H_
#define TIMER_H_

#include <chrono>
#include <mutex>
#include <ctime>

class Timer 
{


    public : 

    Timer();

    ~Timer(); 

    void timeReset();

    double getCurTime();

    private : 

    // current time container 
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time_;

    // mutex lock while writing
    std::mutex mutex_self_;

};


#endif 