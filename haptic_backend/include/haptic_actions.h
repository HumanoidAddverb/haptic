/**
 * @file haptic_actions.h
 * @author Rajesh Kumar (rajesh.kumar01@addverb.com)
 * @brief Haptic Actions list : the list 
 * of actions which the haptic device can take 
 * @version 0.1
 * @date 2023-07-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef HAPTIC_ACTIONS_H_
#define HAPTIC_ACTIONS_H_

/**
 * @brief Sequence of the haptic actions which are 
 * requisite 
 * 
 */
enum class HappActions
{
    no_action = 0,
    start = 1,
    stop = 2,
    error = 3,
    pause = 4
};

/**
 * @brief Tasks for the haptic engine 
 * to implement
 * 
 */
enum class HappEngineTasks
{
    nothing = 0, 
    start = 1,
    read = 2,
    write = 3,
    error = 4,
    stop = 5
};

#endif 