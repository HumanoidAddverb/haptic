/**
 * @file read_write.h
 * @author Rajesh Kumar (rajesh.kumar01@addverb.com)
 * @brief The structure represents how the engine will
 * transmit and receive the force and the motion data
 * along with the error codes representing the error on
 * the haptic device
 * @version 0.1
 * @date 2023-07-08
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef READ_WRITE_H_
#define READ_WRITE_H_

#include <eigen3/Eigen/Core>

#include <iostream>

#include "type_defs.h"

// definition of the vector of the joints contained in the device 
typedef Eigen::Matrix<double, DOFS_IN_PARALLEL,1> JOINT_VEC ;

// definition of 6x1 vector 
typedef Eigen::Matrix<double, 6,1> EE_VEC;

// definition of a 3x1 vector 
typedef Eigen::Matrix<double, 3,1> MOTION_VEC;

// different control modes 
enum class ControlMode
{
    torque = 2,
    position = 1, 
    velocity = 0
};


/**
 * @brief Description of the data types 
 * for the 
 * 
 */
namespace AddMotion
{
    // motion data to be sent to the 
    // exposed api 
    struct HapMotionData
    {
        EE_VEC data ; 
        EE_VEC pos_data; 
        int joy1; 
        int joy2; 

        void print()
        {
            // std::cout<<"Vel data = "<<data.transpose()<<std::endl;
            std::cout<<"Pos data = "<<pos_data.transpose()<<std::endl; 
            std::cout<<"Joy stick button 1 status = "<<joy1<<std::endl;
            std::cout<<"Joy stick button 2 status = "<<joy2<<std::endl; 
        }
    };

    // force data received from the exposed api 
    struct HapForceData
    {
        EE_VEC force; 

        void print()
        {
            std::cout<<"Force = "<<force.transpose()<<std::endl;
        }
    }; 


    // status of the complete system to to 
    // be implemented to the exposed api 
    struct StatusWord
    {
        int status; 
    };

    // Description of the joint data 
    struct JointData
    {
        JOINT_VEC pos_data;
        JOINT_VEC vel_data; 

        void print()
        {
            std::cout<<"Position = "<<pos_data.transpose()<<std::endl; 
            std::cout<<"Velocity = "<<vel_data.transpose()<<std::endl; 
        }
    };

    // Actuator data description 
    struct ActuatorData
    {
        JointData joint_data; 
        JOINT_VEC tor_data;
        JOINT_VEC code;

        void print()
        {
            std::cout<<"Joint data = "<<std::endl;
            joint_data.print(); 
            std::cout<<"Torque data = "<<tor_data.transpose()<<std::endl; 
            std::cout<<"Code = "<<code.transpose()<<std::endl; 

        }
    };

    // Device data description 
    struct DeviceData
    {
        int joy1; 
        int joy2;
        ActuatorData joint_data; 
        Eigen::Matrix<double, 3,1> angular_pose; 
        HapForceData outForce_;

        // print the device data
        void print()
        {
            std::cout<<"Joint vec print = "<<std::endl; 
            joint_data.print(); 
            std::cout<<"Angular Pose = "<<angular_pose.transpose()<<std::endl; 
            std::cout<<"     "<<std::endl; 
            // outForce_.print();
            
        }

    };

    // Control output description 
    struct ControlOutput
    {
        JOINT_VEC control_output; 
        ControlMode mode; 
        HapMotionData outMotion_; 
        int error; 
    };

    // Precontrol data description 
    struct PreControlData
    {
        DeviceData dev_; 
        HapMotionData outMotion_; 
        ControlMode mode; 
    };

    // Consists of the initialization parameters 
    // for the lower level     
    struct InitializationConfig
    {

    };


}

#endif 