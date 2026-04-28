/**
 * @file haptic_utility.h
 * @author Rajesh Kumar (rajesh.kumar01@addverb.com)
 * @brief Haptic utility class to have the allied
 * implementations like kinematics to be used in the
 * controller as well as the safety modules as and
 * when required
 * @version 0.1
 * @date 2023-07-13
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef HAPTIC_UTILITY_H_
#define HAPTIC_UTILITY_H_

#include "kd_interface.h"
#include "read_write.h"
#include "utility_class_interface.h"
#include "moving_average.h"
#include "time_derivative.h"
#include "five_point_derivative.h"

#include <memory>
#include <stddef.h>
#include <utility>

#define AVG_LENGTH_VEL 1000
#define AVG_LENGTH_POS 200
#define TRANS_ROFF 1000.0
#define ROTATE_ROFF 57.3

/**
 * @brief Haptic utility implementation for allied
 * tasks in different classes
 *
 */
class HapticUtility : public UtilityClassInterface
{

public:
    // Constructor call
    inline HapticUtility(std::unique_ptr<KDInterface> &inp)
    {
        kd_ = std::move(inp);
        is_derivative_setup_ = false;
        filter_ = std::make_unique<MovingAverage<Eigen::VectorXd>>(AVG_LENGTH_POS, Eigen::VectorXd::Zero(6));
        outFk_ = Eigen::VectorXd::Zero(6); 
        reading_ = true; 
    };

    // destructor call
    inline ~HapticUtility(){};

    // provide data to be input from the haptic device
    AddMotion::PreControlData provideInput(const AddMotion::PreControlData &data)
    {
        data_ = data;

        performInputSequence_();

        return data_;
    }

    // provide output for the controller; gives the torque
    AddMotion::PreControlData provideOutput(const AddMotion::PreControlData &data, int val)
    {
        data_ = data;
        if (val == 0)
        {

            performHapControlSequence_();
            return data_;
        }

        return data_;
    }

private:
    // pointer to kinematics and dynamics
    std::unique_ptr<KDInterface> kd_;

    // local container of the device data
    AddMotion::PreControlData data_;

    // Perform the data required for the haptic control sequence
    // @todo : how is it to be taken care of ?
    void performHapControlSequence_();

    // perform the input sequence motion
    void performInputSequence_();

    // variable to check if the derivative is setup or not
    bool is_derivative_setup_;

    // estimate the platform velocity and pass it acros
    Eigen::VectorXd estimatePlatformVelocity_();

    /// @brief To save the fk sol 
    Eigen::VectorXd outFk_;

    // pointer to the filter output
    std::unique_ptr<TimeDerivative<Eigen::VectorXd, FivePointDerivative<Eigen::VectorXd>>> filter_out_;

    // pointer to the moving average filter 
    std::unique_ptr<MovingAverage<Eigen::VectorXd>> filter_; 

    // flag to check if the system is running or not 
    bool reading_; 

    /// @brief Quantize the data 
    void quantize_(); 
};

#endif