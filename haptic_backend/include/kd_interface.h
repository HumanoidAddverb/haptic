/**
 * @file kd_interface.h
 * @author Rajesh Kumar (rajesh.kumar01@addverb.com)
 * @brief Kinematic and Dynamic Interface for the control of 
 * the haptic device 
 * @version 0.1
 * @date 2023-07-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef KD_INTERFACE_H_
#define KD_INTERFACE_H_

#include "pose.h"
#include "read_write.h"
#include <eigen3/Eigen/Core>

enum class KDErrorCode
{
    eNoError = 0,
    eSingular = 1,
    eReachedNaN = 2
};

class KDInterface 
{

    public :

    virtual ~KDInterface() {}; 

    virtual bool setJointData(AddMotion::JointData data) = 0;

    virtual bool setAngularPose(Eigen::VectorXd angularpose) = 0; 

    virtual Pose doFK() = 0; 

    virtual Eigen::VectorXd doIK(Pose) = 0; 

    virtual Eigen::VectorXd getJointTorque(Eigen::VectorXd force) = 0; 

    virtual Eigen::VectorXd getPlatformVelocity() = 0; 

    virtual Eigen::VectorXd getPlatformVelocityNumerical() = 0; 

    virtual KDErrorCode getError() = 0; 

};

#endif 