/**
 * @file null_pointer_exception.h
 * @author Ishita Gupta 
 * @brief Exception to be thrown when a null pointer is encountered
 * @version 0.1
 * @date 2023-09-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef NULL_POINTER_EXCEPTION_H_
#define NULL_POINTER_EXCEPTION_H_

#include "custom_exception.h"

class NullPointerException : public CustomException {
public:
  explicit NullPointerException(const std::string& msg) : CustomException("Null Pointer Exception: " + msg), logger_(LockFreeQueueLogger::getInstance()) {
    logger_ >> (NERROR) << "Null Pointer Exception: " + msg;
  }
private:
  LoggingInterfaceNew& logger_;

};

#endif