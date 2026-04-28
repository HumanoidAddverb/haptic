/**
 * @file bb_configs.h
 * @author Rajesh Kumar (rajesh.kumar01@addverb.com)
 * @brief Configuration parameters requried for the beagle 
 * bone 
 * @version 0.1
 * @date 2023-07-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef BB_CONFIGS_H_
#define BB_CONFIGS_H_

// #define ip_save "192.168.7.2"
#define port_save 15482

#define ip_save "192.168.0.2"
// #define port_save 15482


// base offset value for the Aith actuator 
// #define A0_base -82.66
// #define A1_base -23.57
// #define A2_base -103.0
// #define A3_base -147.04
// #define A4_base 101.56
// #define A5_base -107 

#define A0_base 0
#define A1_base 0
#define A2_base 0
#define A3_base 0
#define A4_base 0
#define A5_base 0

#define HAP_FREQUENCY 1500.0

#define tor_fac 277.7
#define vel_fac 0.017

#define MAX_SIZE 20

#define TX_MODE 2
#define FUNCTION_CODE 0


#define ANG_1 -0.06 
#define ANG_2 0.065
#define ANG_3 1.55

#define KIN_DEFAULT 9.0
#define A0_KIN KIN_DEFAULT
#define A1_KIN KIN_DEFAULT
#define A2_KIN KIN_DEFAULT
#define A3_KIN KIN_DEFAULT
#define A4_KIN KIN_DEFAULT
#define A5_KIN KIN_DEFAULT


#define Z_OFFSET  -0.17
#define X_OFFSET 0.08
#define Y_OFFSET -0.0
#define X_ROTATION 0
#define Y_ROTATION 0
#define Z_ROTATION  0


#endif 