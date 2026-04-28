/**
 * @file socket_send_exception.h
 * @author Ishita Gupta (ishita.gupta@addverb.com)
 * @brief Exception to be thrown when an error occurs during socket send operation
 * @version 0.1
 * @date 2023-09-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef SOCKET_SEND_EXCEPTION_H_
#define SOCKET_SEND_EXCEPTION_H_

#include "custom_exception.h"

class SocketSendException : public CustomException {
public:
  explicit SocketSendException(int errorCode) : CustomException(getErrorMessage(errorCode)), errorCode_(errorCode), logger_ (LockFreeQueueLogger::getInstance()) {
    logger_ >> (NERROR) << "Socket Send Exception: " + getErrorMessage(errorCode_);
  }
  int getErrorCode() const {
    return errorCode_;
  } 

private:
  int errorCode_;
  LoggingInterfaceNew& logger_;
  
  /**
   * @brief Get the Error Message string
   * 
   * @param errorCode 
   * @return std::string: error description message 
   *
   */
  static std::string getErrorMessage(int errorCode) {
    switch (errorCode) {
      case EACCES: return "Permission denied.";
      case EWOULDBLOCK: return "Operation would block.";
      case EPIPE: return "Broken pipe.";
      case EBADF: return "Argument sockfd is an invalid descriptor.";
      default: return "Unknown error: " + std::string(std::strerror(errorCode));
    }
  }
};

#endif
