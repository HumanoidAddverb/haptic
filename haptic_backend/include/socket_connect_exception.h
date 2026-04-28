#ifndef SOCKET_CONNECT_EXCEPTION_H_
#define SOCKET_CONNECT_EXCEPTION_H_

#include "custom_exception.h"

class SocketConnectException : public CustomException {
public:
  explicit SocketConnectException(int errorCode) : CustomException(getErrorMessage(errorCode)), errorCode_(errorCode), logger_(LockFreeQueueLogger::getInstance()) {
    logger_ >> (NERROR) << "Socket Connect Exception: " + getErrorMessage(errorCode_);
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
