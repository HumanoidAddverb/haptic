/**
 * @file haptic_builder_interface.h
 * @author Rajesh Kumar (rajesh.kumar01@addverb.com)
 * @brief Haptic Builder Interface implementation to build 
 * the description of a new haptic device within the specified 
 * symmetry constraints; the only input is the description 
 * of the base platform 
 * @version 0.1
 * @date 2023-07-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef HAPTIC_BUILDER_INTERFACE_H_
#define HAPTIC_BUILDER_INTERFACE_H_

#include "pose.h"
#include "parallel_robot.h"

/**
 * @brief Haptic Builder Interface : to build based 
 * on the description of the bottom platform 
 * 
 */
class HapticBuilderInterface 
{

    public : 

    virtual ~HapticBuilderInterface() {}; 

    virtual void addBase(Pose &) = 0; 

    virtual ParallelRobot getRobot() = 0; 

    virtual void build() = 0; 

};


#endif 

