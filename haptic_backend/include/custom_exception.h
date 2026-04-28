/**
 * @file custom_exceptions.h
 * @author Ishita Gupta (ishita.gupta@addverb.com)
 * @brief Base class for custom exceptions of the application.
 * @version 0.1
 * @date 2023-09-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef CUSTOM_EXCEPTION_H_
#define CUSTOM_EXCEPTION_H_

#include <stdexcept>
#include "logging_interface_new.h"
#include "lock_free_queue_logger.h"

class CustomException : public std::runtime_error {
public:
  explicit CustomException(const std::string& msg) : std::runtime_error(msg), logger_(LockFreeQueueLogger::getInstance()) {
    // log/display
    logger_ = LockFreeQueueLogger::getInstance();
    logger_ >> (NERROR) << msg;
  }
private:
  LoggingInterfaceNew& logger_;

};

#endif