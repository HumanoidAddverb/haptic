/**
 * @file logger_factory.h
 * @author Rajesh Kumar (rajesh.kumar01@addverb.com)
 * @brief Logger Factory to return the pointer 
 * @version 0.1
 * @date 2023-09-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef LOGGER_FACTORY_H_
#define LOGGER_FACTORY_H_ 

#include "logging_interface.h"
#include "logging_enums.h"
#include "logging_stack.h"

/**
 * @brief Logger factory for different kinds of loggers ; 
 * the state loggers will be singleton while the 
 * data loggers will be separate implementations of the 
 * system 
 * 
 */
namespace LoggerFactory 
{
    LoggingInterface *createLogger(LOG::LOGGER_TYPE); 
};

#endif 