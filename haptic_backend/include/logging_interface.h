/**
 * @file logging_interface.h
 * @author Rajesh Kumar (rajesh.kumar01@addverb.com)
 * @brief Logging Interface : interface for the logger 
 * @version 0.1
 * @date 2023-09-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef LOGGING_INTERFACE_H_
#define LOGGING_INTERFACE_H_

#include <string>
#include "logging_enums.h"
#include <functional>

/**
 * @brief Interface for Logging primarily a COR pattern 
 * and a singleton to avoid 
 * 
 */

class LoggingInterface
{

    public :

    virtual ~LoggingInterface() {};
    

    virtual LoggingInterface &operator << (const std::string &msg) = 0; 

    virtual LoggingInterface &operator >> (const LOG::LOG_TYPE &msg) = 0; 


};

#endif 