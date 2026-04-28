/**
 * @file utility_task_interface.h
 * @author Rajesh Kumar (rajesh.kumar01@addverb.com)
 * @brief Utility class interface to be used by different 
 * controller classes or safety rules to use different 
 * implementations like kinematics 
 * @version 0.1
 * @date 2023-07-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef UTILITY_TASK_INTERFACE_H_
#define UTILITY_TASK_INTERFACE_H_

#include <string> 
#include <memory>

#include "read_write.h"

/**
 * @brief Class containing the different
 * types of pointers like kinematics or other 
 * utilities as required by different types of 
 * controllers 
 * The developer should ensure that the inputs 
 * and outputs are compatible; always returns a 
 * local reference
 * 
 */
class UtilityClassInterface
{

    public :

    virtual ~UtilityClassInterface() {};

    virtual AddMotion::PreControlData provideInput(const AddMotion::PreControlData &data) = 0;


    virtual AddMotion::PreControlData provideOutput(const AddMotion::PreControlData &, int) = 0;  
};


#endif
