/**
 * @file dummy_client.h
 * @author Rajesh Kumar (rajesh.kumar01@addverb.com)
 * @brief Dummy client class to be used for debugging purposes 
 * @version 0.1
 * @date 2023-08-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef DUMMY_CLIENT_H_
#define DUMMY_CLIENT_H_

#include "lower_level_interface.h"

#include <iostream>

/**
 * @brief Dummy client class for debugging process 
 * 
 */
class DummyClient : public LowerLevelInterface {
public:
  inline DummyClient() {};
  inline ~DummyClient() {};
  AddMotion::DeviceData readDataLL() {
    AddMotion::DeviceData out; 
    for (int i = 0; i < 6; i++) {
      out.joint_data.joint_data.pos_data(i) = 0.0;
      out.joint_data.joint_data.vel_data(i) = 0.0;
    } 
    out.joint_data.joint_data.vel_data(0) = 5.0;
    out.joint_data.joint_data.vel_data(1) = 0.0;
    out.joint_data.joint_data.vel_data(2) = 0.0;
    out.joint_data.joint_data.vel_data(3) = 0.0;
    return out;
  };

  bool writeDataLL(const AddMotion::ControlOutput &out) {
    return true; 
  }
  bool setup(const AddMotion::InitializationConfig &tmp) {
    std::cout<<"within dummy client setup"<<std::endl;
    return true;
  }
  bool stopLL() {return true;}
  bool startLL() {
    return true;
  }
  int getError() {return 0; }
};

#endif 
