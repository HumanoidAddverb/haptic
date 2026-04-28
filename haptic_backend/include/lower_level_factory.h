/**
 * @file LowerLevelFactory.h
 * @author Rajesh Kumar (rajesh.kumar01@addverb.com)
 * @brief Servo Factory : to create the lower level 
 * interface : concrete implementation of the factory 
 * interface 
 * @version 0.1
 * @date 2023-07-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef LOWER_LEVEL_FACTORY_H_
#define LOWER_LEVEL_FACTORY_H_

// #ifndef NDEBUG
// #define NDEBUG
// #endif

#include "lower_level_interface.h"
#include "bb_client.h"
#include <memory.h>

/**
 * @brief Lower level Factory : to create the pointers to the 
 * lower level objects to communicate to the beaglebone for now 
 * 
 */
class LowerLevelFactory 
{

    public:

    // constructor call
    LowerLevelFactory() {};

    // destructor call 
    ~LowerLevelFactory() {};

    // setup the lower level 
    static std::unique_ptr<LowerLevelInterface> setLowerLevel(int, const AddMotion::InitializationConfig &inp);

    private : 

    // static pointer to the lower level to ensure the pointer is created 
    // only once 
    static std::unique_ptr<LowerLevelInterface> ptr_;

};

#endif