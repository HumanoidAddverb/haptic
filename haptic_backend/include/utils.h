/**
 * @file utils.h
 * @author Rajesh Kumar (rajesh.kumar01@addverb.com)
 * @brief Compose the utility class for the 
 * @version 0.1
 * @date 2023-07-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef UTILS_H_
#define UTILS_H_

#include <iostream>
#include <eigen3/Eigen/Geometry>
#include <deque>
#include <vector> 
#include <eigen3/Eigen/Geometry>
#include <math.h>

/*
 * @brief set of helper functions
 * 
 */

namespace utils
{
     // computation of the singular value decomposition 
     std::vector<Eigen::MatrixXd> computeSVD(const Eigen::MatrixXd &mat) ;

     // convert vector to rotation matrix 
     Eigen::MatrixXd vec2RotMat(const Eigen::VectorXd &axis_angle);

     // convert rotation matrix to a vector 
     Eigen::VectorXd rotMat2Vec(const Eigen::Matrix3d &rotation_mat);

     // get the determinant of a matrix 
     double matrixDet(const Eigen::MatrixXd &mat);

     // get the norm of a vector 
     double vectorNorm(const Eigen::VectorXd &vec_norm);

     // get screw from SE3
     Eigen::VectorXd screwfromSE3(const Eigen::MatrixXd &pose);

     // get SE3 from screw
     Eigen::MatrixXd SE3fromscrew(const Eigen::VectorXd &screw);

     // get the cross product matrix 
     Eigen::MatrixXd getCrossMat(const Eigen::VectorXd &screw);

     // get the rotation matrix about x 
     Eigen::MatrixXd getRotx(const double &q);

     // get the rotation matrix  about y 
     Eigen::MatrixXd getRoty(const double &q);

     // get the rotation matrix about z 
     Eigen::MatrixXd getRotz(const double &q);

     // do a differential SE3 solver 
     Eigen::VectorXd diffSE3Solver(const Eigen::MatrixXd &A, const Eigen::MatrixXd &B);

     // five point derivative in the queue form 
     Eigen::VectorXd fpDerive(const std::deque<Eigen::VectorXd> &prev_data, const double &deltaT_ime);

     // trapezoidal integral of the queue 
     Eigen::VectorXd trapIntegral(const std::deque<Eigen::VectorXd> &cur_data, const double &time_d);

     // pseudo inverse of a matrix 
     Eigen::MatrixXd pseudoInverse(const Eigen::MatrixXd &mat);

     // matrix logarithm of a rotation matrix 
     Eigen::VectorXd rotMatLog(const Eigen::MatrixXd &mat);

     // rpy and xyz from an SE3 matrix 
     Eigen::VectorXd rpyxyzfromSE3(const Eigen::MatrixXd &pose);

     // get SE3 from rpy and xyz
     Eigen::MatrixXd SE3fromrpyxyz(const Eigen::VectorXd &vec);

     // get the cross product matrix in a non normalized sense 
     Eigen::MatrixXd getCrossMatNonNormalized(const Eigen::VectorXd &screw);
     
     // gets the max value of the diagonal 
     int getMaxDiagonalDir(const Eigen::MatrixXd &mat);

     // give point derivative in midpoint form using the function form 
     Eigen::VectorXd fpDeriveMidpoint(Eigen::VectorXd (*f)(Eigen::VectorXd), const Eigen::VectorXd &, const double &);

     // five point derivative in the midpoint form 
     Eigen::VectorXd fpDeriveMidpoint(const std::deque<Eigen::VectorXd> &prev_data, const double &deltaT_ime);

     // implement the gestep function 
     double gestep(const double&);

     // convert eigen vector to string 
     std::string convertEigenToString(const Eigen::VectorXd &vec);

     // get intersection of two spheres 
     bool getIntersectionSphere(std::pair<Eigen::VectorXd, Eigen::VectorXd> &coord, const std::vector<Eigen::VectorXd> &center, const std::vector<double> &radii);

     /// @brief Convert RPY to rot vec 
     /// @return 
     Eigen::VectorXd convertRPYtorotVec(const Eigen::VectorXd &); 

};

#endif