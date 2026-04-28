/**
 * @file lock_free_queue_logger.h
 * @author Ishita Gupta (ishita.gupta@addverb.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef LOCK_FREE_QUEUE_LOGGER_H_
#define LOCK_FREE_QUEUE_LOGGER_H_

#include "logging_interface_new.h"
#include <atomic>
#include <mutex>
#include <thread>
#include <vector>
#include <fstream>
#include <chrono>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

#include "pc_queue.h"  
#include "logger_constants.h"

/**
 * @brief LogData struct contains: 
 * 1) message string 
 * 2) log type `[error, fatal, debug, info]` 
 * 3) log timestamp
 * 
 */
struct LogData {
  std::string message;
  NLOG::NLOG_TYPE type;
  double timestamp;
};

class LockFreeQueueLogger : public LoggingInterfaceNew {
public:

  /// @brief Meyer's singleton implementation for the Logger
  /// @return: Reference to the static instance of the logger created
  static LoggingInterfaceNew& getInstance();
  
  /// @brief Overload operator to write log messages
  /// @param msg: log message string 
  /// @return 
  LoggingInterfaceNew& operator << (const std::string &msg) override;

  /// @brief Overload operator to specify Log type
  /// @param msg: Log type enum 
  /// @return 
  LoggingInterfaceNew& operator >> (const NLOG::NLOG_TYPE &msg) override;
  
  /// @brief Default destructor
  ~LockFreeQueueLogger();
  
  /**
   * @brief flush all queued logs to the log file.
   * 
   */
  void flushLogs();
  
private:
  
  /// @brief private constructor
  LockFreeQueueLogger();
  
  /// @brief Initialize logger - called inside the default constructor
  void initialize_();
  
  /// @brief A lock-free queue for buffering log messages.
  pc_queue<LogData> queue_;
  
  /// @brief 
  std::unique_ptr<std::ofstream> handler_;
  
  /// @brief Atomic flag to indicate whether the logger is running.
  std::atomic<bool> running_;
  
  /// @brief Log type - Error, Info, Debug, Fatal
  NLOG::NLOG_TYPE type_;
  
  /// @brief Log file path
  std::string filePath_;
  
  /// @brief Initial time of logging
  static std::chrono::time_point<std::chrono::high_resolution_clock> start_time_;
  
  /// @brief Boolean - true if initialization is successful. 
  bool initialized_ = false;

};

#endif  
