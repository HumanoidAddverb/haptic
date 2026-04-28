/**
 * @file engine_config.h
 * @author Rajesh Kumar (rajesh.kumar01@addverb.com)
 * @brief Description of the configuration
 * elements required to run the robot
 * @version 0.1
 * @date 2023-07-29
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef ENGINE_CONFIG_H_
#define ENGINE_CONFIG_H_

/**
 * @brief Types of the controllers which are allowd
 *
 */
enum class ControllerType
{
    eHapticControl = 0
};

/**
 * @brief Version of the haptic
 * device; used by the builder interface
 *
 */
enum class DeviceVersion
{
    eV1_0 = 0
};

/**
 * @brief Controller; device
 * and other configurations for the haptic
 * device
 *
 */

#define ControllerMain ControllerType::eHapticControl
#define Device DeviceVersion::eV1_0

#endif