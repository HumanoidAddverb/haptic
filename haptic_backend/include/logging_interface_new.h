#ifndef LOGGING_INTERFACE_NEW_H_
#define LOGGING_INTERFACE_NEW_H_

#include <string>
#include <functional>

#include "logging_enums_new.h"

class LoggingInterfaceNew {
public :
  virtual ~LoggingInterfaceNew() {};
  virtual LoggingInterfaceNew &operator << (const std::string &msg) = 0; 
  virtual LoggingInterfaceNew &operator >> (const NLOG::NLOG_TYPE &msg) = 0; 
  virtual void flushLogs() = 0;
};

#endif 