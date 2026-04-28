/**
 * @file haptic_V1_builder.h
 * @author Rajesh Kumar (rajesh.kumar01@addverb.com)
 * @brief Contains the description of the haptic device 
 * under use based on parsing the data from the header  
 * @version 0.1
 * @date 2023-07-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef HAPTIC_V1_BUILDER_H_
#define HAPTIC_V1_BUILDER_H_

#include "haptic_builder_interface.h"
#include "haptic_v1.h"

/**
 * @brief Returns the parallel robot based on the 
 * 
 */
class HapticV1Builder : public HapticBuilderInterface 
{
    public : 

    inline HapticV1Builder() {};

    inline ~HapticV1Builder() {}; 

    void addBase(Pose &);

    void build(); 

    ParallelRobot getRobot(); 


    private : 

    // pose of the base of the platform 
    Pose base_;  

    // description of the parallel robot which is to be built 
    ParallelRobot robot_;

    // build the features of the robot 
    void buildAlliedFeatures_(); 

    // build the bottom points involved with the robot 
    void buildBottomPlatform_(); 

    // build the top poses of the points attached to the bottom 
    // platfrom
    void buildTopPlatform_(); 

    // build the servo planar angles 
    void buildServoPlanarAngles_(); 

};

#endif 

