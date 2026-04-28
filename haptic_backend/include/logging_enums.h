/**
 * @file logging_enums.h
 * @author Rajesh Kumar (rajesh.kumar01@addverb.com)
 * @brief Logging enums for the different types 
 * of logging entities 
 * @version 0.1
 * @date 2023-09-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef LOGGING_ENUMS_H_
#define LOGGING_ENUMS_H_

namespace LOG
{
        enum LOGGER_TYPE {
            stack, data
        };

        enum LOG_TYPE {
            Debug, 
            Info, 
            Warn, 
            Error, 
            Fatal
        }; 

}

#define DEBUG LOG::LOG_TYPE::Debug 
#define INFO LOG::LOG_TYPE::Info 
#define WARN LOG::LOG_TYPE::Warn 
#define ERROR LOG::LOG_TYPE::Error 
#define FATAL LOG::LOG_TYPE::Fatal 



#endif 