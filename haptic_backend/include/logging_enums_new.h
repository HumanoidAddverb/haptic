/**
 * @file logging_enums_new.h
 * @author Rajesh Kumar (rajesh.kumar01@addverb.com)
 * @brief Logging enums for the different types 
 * of logging entities 
 * @version 0.1
 * @date 2023-09-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef LOGGING_ENUMS_NEW_H_
#define LOGGING_ENUMS_NEW_H_

namespace NLOG {
  enum NLOGGER_TYPE {
    stack, 
    data
  };

  enum NLOG_TYPE {
    Debug, 
    Info, 
    Warn, 
    Error, 
    Fatal
  }; 
}

#define DEBUG_LOG NLOG::NLOG_TYPE::Debug 
#define NINFO NLOG::NLOG_TYPE::Info 
#define NWARN NLOG::NLOG_TYPE::Warn 
#define NERROR NLOG::NLOG_TYPE::Error 
#define NFATAL NLOG::NLOG_TYPE::Fatal 

#endif 
