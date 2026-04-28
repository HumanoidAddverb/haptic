/**
 * @file safety_impl.h
 * @author Rajesh Kumar (rajesh.kumar01@addverb.com)
 * @brief Implementation of the safety modules 
 * @version 0.1
 * @date 2023-07-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef SAFETY_IMPL_H_
#define SAFETY_IMPL_H_

#include "safety_interface.h"
#include "utility_class_interface.h"
#include "read_write.h"

class SafetyImpl : public SafetyInterface 
{

    public : 

    inline SafetyImpl() {};

    inline ~SafetyImpl() {};

    bool setup(); 

    bool performReadSafety(std::unique_ptr<UtilityClassInterface> &ptr, AddMotion::ActuatorData &data) ; 

    bool performWriteSafety(std::unique_ptr<UtilityClassInterface> &ptr, AddMotion::ControlOutput &data) ; 

};

#endif 