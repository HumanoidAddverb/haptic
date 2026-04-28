/**
 * @file haptic_builder_factory.h
 * @author Rajesh Kumar (rajesh.kumar01@addverb.com)
 * @brief Haptic Builder Factory synthesis 
 * @version 0.1
 * @date 2023-07-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef HAPTIC_BUILDER_FACTORY_H_
#define HAPTIC_BUILDER_FACTORY_H_

#include "haptic_builder_interface.h"
#include "engine_config.h"
#include "haptic_v1_builder.h"
#include <memory>

/**
 * @brief Return the haptic builder implementation 
 * 
 */
class HapticBuilderFactory
{
    public : 

    HapticBuilderFactory() {};

    ~HapticBuilderFactory() {}; 

    static std::unique_ptr<HapticBuilderInterface> create(DeviceVersion); 

};

#endif 