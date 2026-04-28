/**
 * @file moving_average.h
 * @author Rajesh Kumar (rajesh.kumar01@addverb.com)
 * @brief Perform moving average; once registers; keeps
 * putting the values out : templated class
 * @version 0.1
 * @date 2023-09-05
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef MOVING_AVERAGE_H_
#define MOVING_AVERAGE_H_

#include <deque>
#include <eigen3/Eigen/Core>

/**
 * @brief Perform the moving average
 *
 */
template <typename T>
class MovingAverage
{
public:
    inline MovingAverage(int length, T init, int type = 0) : length_(length), out_(init), type_(type) {
        init_ = init; 
    };

    inline ~MovingAverage(){};

    /// @brief Add the data to the queue
    /// @param val
    /// @return
    MovingAverage<T> &addData(T val)
    {
        T tmp_val; 

        while (avg_.size() <= length_)
        {
            avg_.push_back(val);
            out_ = out_ + val / length_;
        }
        if (avg_.size() > length_)
        {
            T tmp = avg_.front();

            avg_.pop_front();

            out_ = out_ - tmp / length_;
        }

        return *this;
    }

    /// @brief Returns the filtered value
    /// @return
    T getData()
    {
        return out_;
    }

    void reset()
    {
        out_ = init_;
        if (avg_.size() > 0)
        {
            avg_.clear();
        }
    }

private:
    // lenght of the array
    int length_;

    /// @brief Variable storing the average
    T out_;

    /// @brief Type of initialization 
    int type_;

    /// @brief Variable average queue
    std::deque<T> avg_;

    /// @brief Initialization 
    T init_;
    
};

#endif