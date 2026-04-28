/**
 * @file time_derivative.h
 * @author Rajesh Kumar (rajesh.kumar01@addverb.com)
 * @brief Class to compute the time derivative 
 * @version 0.1
 * @date 2023-09-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef TIME_DERIVATIVE_H_
#define TIME_DERIVATIVE_H_

#include "memory"

template <typename T, typename Derivative> 
class TimeDerivative 
{

    public : 

    TimeDerivative(int length, T init) {
        der_ = std::make_unique<Derivative>(length, init); 
            };

    ~TimeDerivative() {}; 

    // reset 
    void reset()
    {
        der_->reset(); 
    }

    // add the data 
    void addData(T val)
    {
        der_->addData(val); 
    }

    // get the data back 
    T getData() const 
    {
        return der_->getData(); 
    }




    private :

    // object of the derivative class 
    std::unique_ptr<Derivative> der_; 


};




#endif 