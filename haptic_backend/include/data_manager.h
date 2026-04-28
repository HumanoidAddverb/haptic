/**
 * @file data_manager.h
 * @author Rajesh Kumar (rajesh.kumar01@addverb.com)
 * @brief Data manager implementation to communicate 
 * the data between the exposed api and the 
 * haptic device 
 * @version 0.1
 * @date 2023-07-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef DATA_MANAGER_H_
#define DATA_MANAGER_H_

#include <iostream>
#include <mutex>
#include "read_write.h"

/**
 * @brief Data Manager implementation 
 * used for transmission of data 
 * from one end to another 
 * 
 */
class DataManager {
public: 
  static DataManager& instance();
  DataManager(DataManager const&) = delete;     
  void operator=(DataManager const&) = delete;
  
  void                      writeInData(AddMotion::HapMotionData ); 
  void                      writeOutData(AddMotion::HapForceData ); 
  void                      writeInterrupt(int ui_interrupt);
  void                      writePosition(EE_VEC position);
  void                      reset(); 
  int                       readInterrupt() const;
  EE_VEC                    readObjectPosition() const;
  AddMotion::HapMotionData  readInData() const ; 
  AddMotion::HapForceData   readOutData() const ; 

private:
  DataManager();
  ~DataManager();
  // data read from the structure 
  AddMotion::HapMotionData read_;
  // data written to the structure 
  AddMotion::HapForceData write_; 
  // data with ui button status
  int ui_interrupt_;
  // Position vector for the active object.
  EE_VEC position_;
  // mutex to lock the data 
  mutable std::mutex  data_mutex_;
};

#endif 
