/**
 * @file error_manager.h
 * @author Ishita Gupta (ishita.gupta@addverb.com)
 * @brief Error Manager for the application, Error codes are defined in error_codes.h
 * @version 0.1
 * @date 2023-08-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef ERROR_MANAGER_H_
#define ERROR_MANAGER_H_

#include <iostream>
#include <map>
#include <regex>

#include "error_codes.h"
#include "logging_interface_new.h"
#include "lock_free_queue_logger.h"
#include "data_manager.h"

enum class ErrorType {
  Robot,
  UI,
  Simulator
};

class ErrorManager {
public:
  static ErrorManager& instance();
  ErrorManager(ErrorManager const&) = delete;
  void operator=(ErrorManager const&) = delete; 
  void setError(Errors error);
  // void displayError(ErrorType error_type);
private:
  ErrorManager();
  ~ErrorManager();
  // void displayUIError_();
  void displayRobotError_();
  std::map<Errors, std::pair<std::string, ErrorType> > errorMessages_;
  LoggingInterfaceNew& logger_;
};

#endif
