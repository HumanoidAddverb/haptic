#ifndef HAPTIC_ENGINE_INTERFACE_H_
#define HAPTIC_ENGINE_INTERFACE_H_

/**
 * @brief Haptic Engine Interface : 
 * does everything which a haptic device 
 * needs to do : takes in the required 
 * force input to be replicated and outs the 
 * velocity 
 * 
 */

#include "read_write.h"

class HapticEngineInterface 
{

    public :

    virtual ~HapticEngineInterface() {};

    virtual bool setup() = 0; 

    virtual bool readMotionData(AddMotion::HapMotionData &) const = 0; 

    virtual bool writeForceData(AddMotion::HapForceData ) = 0; 

    virtual AddMotion::StatusWord pollStatus() const = 0; 

    virtual bool start() = 0; 

    virtual void stop() = 0; 

    virtual bool read() = 0; 

    virtual bool work() = 0;


};

#endif 