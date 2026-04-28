/**
 * @file five_point_derivative.h
 * @author Rajesh Kumar (rajesh.kumar02@addverb.com)
 * @brief Five point derivative implementation 
 * @version 0.1
 * @date 2023-09-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef FIVE_POINT_DERIVATIVE_H_
#define FIVE_POINT_DERIVATIVE_H_

#include "moving_average.h"
#include "memory.h"
#include "timer.h"
#include <iostream>



/**
 * @brief Implementation of the five point derrivative 
 * 
 */
template <typename T> 
class FivePointDerivative
{

    public : 
    

    FivePointDerivative(int length, T init, int type = 0) {
        tm_.timeReset(); 
        init_ = init; 
        start_time_ = tm_.getCurTime();
        length_ = length;  
        filter_ = new MovingAverage<T>(length_, init_); 
        type_ = type; 

    };

    ~FivePointDerivative() {
        delete filter_ ;
    }; 
    
    // reset the queue 
    void reset()
    {
        if (qu_.size()>0)
        {
            qu_.clear();
        }
        filter_->reset();
    }

    // do the filtering 
    void addData(T val)
    {
        while (qu_.size() <= 5)
        {
            qu_.push_back(val); 
        }
        if (qu_.size() > 5)
        {
            qu_.pop_front(); 
        }
        
        diff_t_ = tm_.getCurTime() - start_time_; 
        start_time_ = tm_.getCurTime(); 
        deriv_ = (1.0/(DENO*diff_t_))*(qu_[4]*X0 + qu_[3]*X1 + qu_[2]*X2 + qu_[1]*X3 + qu_[0]*X4);

        deriv_ = filter_->addData(deriv_).getData(); 
    }

    // get the derivative data back 
    T getData() const 
    {
        return deriv_; 
    }


    private :

    // time when the previous iteration was chosen
    double start_time_; 

    // diff t 
    double diff_t_;

    // moving average filter 
    MovingAverage<T> *filter_; 

    // vector of coefficients 
    Eigen::VectorXd coefficients_;

    /// queue containing the elements for the derivative 
    std::deque<T> qu_;  

    /// value of the derivative 
    T deriv_; 

    /// @brief Initial variable 
    T init_; 

    /// @brief Initialization type : 0 same var; 1 : 0 val input 
    int type_;

    /// @brief  coefficients for the derivative 
    const double DENO = 12.0;
    const double X0 = 25;
    const double X1 = -48;
    const double X2 = 36;
    const double X3 = -16;
    const double X4 = 3; 

    // length of the moving average 
    double length_; 

    /// @brief Timer object 
    Timer tm_; 
};

#endif 