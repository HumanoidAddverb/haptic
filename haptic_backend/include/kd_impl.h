/**
 * @file kd_impl.h
 * @author Rajesh Kumar (rajesh.kumar01@addverb.com)
 * @brief Implementation of the kinematics
 * @version 0.1
 * @date 2023-07-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef KD_IMPL_H_
#define KD_IMPL_H_

#include "kd_interface.h"
#include "parallel_robot.h"
#include "utils.h"
#include "five_point_derivative.h"
#include <utility>

/**
 * @brief Implementation of the kinematics 
 * 
 */
class KDImpl : public KDInterface
{

    public : 

    inline KDImpl(ParallelRobot robot) : robot_(robot), jac_(Eigen::MatrixXd::Zero(6,6)) {
            // std::cout<<"Bottom point for i = "<<1<<" is = "<<robot_.getBottomPoints(1).getSE()<<std::endl; 
            // std::cout<<"Bottom point for i = "<<2<<" is = "<<robot_.getBottomPoints(2).getSE()<<std::endl; 

    };

    inline ~KDImpl() {};

    bool setJointData(AddMotion::JointData data); 

    bool setAngularPose(Eigen::VectorXd angularpose); 

    Eigen::VectorXd doIK(Pose); 

    Eigen::VectorXd getJointTorque(Eigen::VectorXd force); 

    Eigen::VectorXd getPlatformVelocity();

    Eigen::VectorXd getPlatformVelocityNumerical(); 

    Pose doFK(); 

    KDErrorCode getError(); 


    private : 

    // angular pose of the top platform 
    Eigen::VectorXd angular_pose_; 


    // description of the error for the device 
    KDErrorCode err_;

    // current configuration of the data
    AddMotion::JointData config_; 

    // description of the parallel robot 
    ParallelRobot robot_; 

    // end effector pose of the manipulandum in a screw form 
    Eigen::VectorXd ee_pose_;

    // Jacobian matrix computations 
    Eigen::MatrixXd jac_;

    // Inverse of the jacobian matrix 
    Eigen::MatrixXd jacMatInv_;


    // get the leg vector 
    bool getLegVector_(std::vector<Eigen::VectorXd> &leg_vec, const Eigen::VectorXd &ee_pose);
    
    // compute the jacobian matrix 
    void computeJac_(); 

    // inverse of the jacobian matrix 
    Eigen::MatrixXd &getJacInv_(); 

    // get the jacobian 
    Eigen::MatrixXd &getJac_(); 

    // check the condition no 
    double checkCondNo_(); 

    // vector of top points 
    std::vector<Pose> top_points_;
    
    // vector of bottom points 
    std::vector<Pose> bottom_points_;
    
    // vector of crankset 
    std::vector<Eigen::VectorXd> crank_set_;

    // vector of legs 
    std::vector<Eigen::VectorXd> leg_vec_;

    /// @brief Output velocity 
    Eigen::VectorXd vel_out_; 
};

#endif 