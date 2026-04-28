#ifndef HAPTIC_V1_H_
#define HAPTIC_V1_H_

/**
 * @brief Description of the coordinates of the bottom points 
 * of a haptic device : it is assumed that the coordinates 
 * of the device are symmetric from the top view; the coordinate
 * 0 and coordinate 5 match 
 * TPIJ represents the coordinate of the ith point in the jth {x,y,z}
 * direction 
 */
#define BP0X 0.06100
#define BP0Y 0.00235
#define BP0Z 0
#define BP5X 0.06100
#define BP5Y -0.00235
#define BP5Z 0

/**
 * @brief Description of the coordinates of the top points 
 * of a haptic device : it is assumed that the coordinates 
 * of the device are symmetric from the top view; the coordinate
 * 2 and coordinate 3 match to the bottom points 0 and 5 for 
 * the v1 haptic device of Addverb Technologies 
 * TPIJ represents the coordinate of the ith point in the jth {x,y,z}
 * direction 
 */
#define TP2X -0.043985
#define TP2Y 0.015620
#define TP2Z 0
#define TP3X -0.043985
#define TP3Y -0.015620
#define TP3Z 0

// Length of the connecting link from the motor 
// to the link 
#define MOTOR_LINK 0.05228

// Leg length of the stewart platform 
#define LEG_LENGTH 0.193

// angular orientation of each of the actuator 
#define PLANAR_ANGLE_VALUE 2*M_PI/3


#endif 