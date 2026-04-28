#ifndef DATA_HANDLER_H_
#define DATA_HANDLER_H_

#include <atomic>

#include "read_write.h"

class DataHandler {
public:
  /**
   * @brief Read and store the latest motion data
   * 
   * @param motion 
   */
  static void readMotionData(const EE_VEC &motion) {
    // std::cout<<"readMotionData()\n";
    motion_data_ = motion;
    // std::cout<<"motion_data_ = ";
    // for(int i = 0;i < 6; i++) {
    //   std::cout<<motion_data_(i)<<" ";
    // }
    // std::cout<<std::endl;
  }

  /**
   * @brief Retrieve the latest motion data
   * 
   * @return EE_VEC 
   */
  static EE_VEC getLatestMotionData() {
    // std::cout<<"getLatestMotionData() motion_data_ = ";
    // for(int i = 0;i < 6; i++) {
    //   std::cout<<motion_data_(i)<<" ";
    // }
    // std::cout<<std::endl;
    return motion_data_;
  }

  /**
   * @brief Read and store the latest force data
   * 
   * @param force 
   */
  static void writeForceData(const Eigen::VectorXd &force) {
    force_data_ = force;
  }

  /**
   * @brief Method to retrieve the latest force data
   * 
   * @return Eigen::VectorXd 
   */
  static Eigen::VectorXd getLatestForceData() {
    return force_data_;
  }
  
  static bool can_start_testing;

private:
  /// @brief To store the latest motion data
  static EE_VEC motion_data_;     
  /// @brief To store the latest force data
  static Eigen::VectorXd force_data_; 

};

EE_VEC DataHandler::motion_data_;
Eigen::VectorXd DataHandler::force_data_;
bool DataHandler::can_start_testing = false;

#endif