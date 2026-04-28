/**
 * @file logging_stack.h
 * @author Rajesh Kumar (rajesh.kumar01@addverb.com)
 * @brief Logging Stack implementation 
 * @version 0.1
 * @date 2023-09-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef LOGGING_STACK_H_
#define LOGGING_STACK_H_

#include "logging_interface.h"
#include <mutex> 
#include <string>
#include <utility>
#include <thread>
#include <fstream>
#include "chrono"
#include <iostream>

/**
 * @brief Logging Class for the implementation 
 * of the stack : 
 * needs to be thread safe and a singleton 
 * can be called from anywhere 
 * 
 */
class LoggingStack : public LoggingInterface
{

    public : 


    ~LoggingStack(); 


    LoggingStack(LoggingStack &other)  = delete; 

    static LoggingInterface *getInstance(); 

    LoggingInterface &operator << (const std::string &msg); 

    LoggingInterface &operator >> (const LOG::LOG_TYPE &msg); 

    protected :

    
    LoggingStack() {setup_();};

    static LoggingInterface *ptr_; 



    private : 

    // max length of the string to be implemented 
    unsigned int charLengthMax_; 

    // message suggesting it cannot be parsed 
    std::string unParsableMessage_; 

    // append the log based on the type message
    void appendLog_(const std::string &msg, const LOG::LOG_TYPE &); 

    // setup the ofstream and other implementations 
    bool setup_(); 

    // file path to log 
    std::string filePath_; 

    // handler to handle the stream 
    std::unique_ptr<std::ofstream> handler_;

    // start time of the initialization of the logger 
    static std::chrono::time_point<std::chrono::high_resolution_clock> start_time_; 

    // log type required in the string 
    LOG::LOG_TYPE type_; 

    // locking mutex 
    std::mutex mut_; 

};


#endif 