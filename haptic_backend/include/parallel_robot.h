/**
 * @file parallel_robot.h
 * @author Rajesh Kumar (rajesh.kumar01@addverb,com)
 * @brief Class which contains the description of the parallel
 * robot in general with certain assumptions of the design
 * of the robot; consult the manual for details
 * @version 0.1
 * @date 2023-07-11
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef PARALLEL_ROBOT_DESCRIPTION_H_
#define PARALLEL_ROBOT_DESCRIPTION_H_

#include <vector>
#include <eigen3/Eigen/Core>

#include "pose.h"
#include "type_defs.h"

/**
 * @brief Stores the description of the parallel robot
 *
 */
class ParallelRobot
{
public:
    ParallelRobot();

    ~ParallelRobot();

    // builder elements : required to be called
    void addBottomPoints(const Pose &, int);
    void addTopPoints(const Pose &, int);
    void addLegLength(double);
    void addBaseFrame(const Pose &);
    void addMotorLinkLength(double);
    void addBaseServoPlanarAngles(double, int);
    void addCenterPlatform(const Pose &); 

    Pose getBottomPoints(int) const;
    Pose getTopPointsLocal(int) const;
    Pose getTopPointsGlobal(int) const;
    Pose getCenterPlatform() const;
    Pose getBaseFrame() const;

    bool getPlanarAngles(std::vector<double> &) const;
    double getLegLength() const;
    double getMotorLinks() const;

private:
    // 4x4 transformation matrices :

    // pose of the base frame; if mounted onto another frame
    Pose base_frame_;

    // pose of the center platform in the global frame 
    Pose center_platform_;

    // bottom points
    Pose bottom_points_[DOFS_IN_PARALLEL];

    // top points in the local frame
    Pose top_points_local_[DOFS_IN_PARALLEL];

    // top points in the global frame
    Pose top_points_global_[DOFS_IN_PARALLEL];

    // vector containig the base servo planar angles
    double base_servo_planar_angles_[DOFS_IN_PARALLEL];

    // length of the leg in consideration
    double length_;

    // length of the motor links in consideration
    double length_motor_links_;
};

#endif
