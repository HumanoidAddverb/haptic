/**
 * @file pose.h
 * @author Rajesh Kumar (rajesh.kumar01@addverb.com)
 * @brief This is a generalized pose class which will use all 
 * the requisite manipulations for a pose for the kinematics' related 
 * computations 
 * @version 0.1
 * @date 2023-07-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef POSE_H_
#define POSE_H_

#include <eigen3/Eigen/Core>
#include "utils.h"
/**
 * @brief Pose utility class to do save pose and 
 * quickly perform manipulations 
 * 
 */
class Pose
{

    public: 

    inline Pose() : mat_4x4_(Eigen::MatrixXd::Identity(4,4)) {};

    inline Pose(const Eigen::MatrixXd &mat) : mat_4x4_(mat) {};

    inline ~Pose() {};

    inline Pose (const Pose &ps) {mat_4x4_ = ps.getSE();}

    void distance(Pose &, double &);

    Pose operator * (Pose input);

    // Pose operator= (Pose input); 

    void getRotationMatrix(Eigen::MatrixXd &);

    void getTransformationMatrix(Eigen::MatrixXd &);

    Eigen::MatrixXd getSO() const ;

    Eigen::MatrixXd getSE() const ; 

    void setSE(Eigen::MatrixXd inp); 

    Pose inverse();

    Pose rotateX(double);

    Pose rotateY(double);

    Pose rotateZ(double); 

    Pose prerotateX(double);

    Pose prerotateY(double);

    Pose prerotateZ(double); 

    void getScrew(Eigen::VectorXd &out_pose); 
 
    void translate(const Eigen::VectorXd &);

    void rotateRodriguez(const Eigen::VectorXd &angle_axis);

    void rotateRpy(const Eigen::VectorXd &xyz_rpy);

    void prerotateRpy(const Eigen::VectorXd &xyz_rpy); 

    void prerotateMat(const Eigen::MatrixXd &); 

    void rotateMat(const Eigen::MatrixXd &);

    void transformXyzrpy(const Eigen::VectorXd &);

    void transformScrew(const Eigen::VectorXd &);

    void getTranslation(Eigen::VectorXd &);

    Eigen::VectorXd getTranslation(); 

    void transform(const Eigen::MatrixXd &mat);

    void rotateVector(Eigen::VectorXd &out, const Eigen::VectorXd &in);
    
    void print();     

    Eigen::VectorXd screw(); 

    private :


    // 4x4 transformation matrix container 
    Eigen::MatrixXd mat_4x4_;

};


#endif