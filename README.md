# Haptic ROS2

A ROS2 SDK for interfacing with haptic devices, enabling bidirectional data communication for position/velocity sensing and force feedback control.

## Overview

This SDK provides a simple interface to:
- Read position, velocity, and button state data from haptic devices
- Send force feedback commands to haptic devices
- Integrate haptic control into ROS2-based robotic systems

## Data Specifications

### Read Data (Motion Data)

Subscribe to `/hap/motion_data` to receive haptic device state:
```
float64[6] platform_velocity  # Linear and angular velocities [vx, vy, vz, wx, wy, wz]
float64[6] platform_position  # Position and orientation [x, y, z, roll, pitch, yaw]
int16 enable_button           # Touch sensor status
int16 grab_button             # Click button status
```

**Data Contents:**
- `platform_velocity`: Joystick velocity in 3D space (linear and angular)
- `platform_position`: Joystick position and orientation in 3D space
- `enable_button`: Status of the touch/enable sensor
- `grab_button`: Status of the grab/click button

### Write Data (Force Feedback)

Publish to `/hap/force_data` to send force feedback commands:
```
float64[6] force_data  # [force_x, force_y, force_z, torque_x, torque_y, torque_z]
```

 ***IMPORTANT NOTE:*** Ensure all force and torque values are within the range **[-40, 40]** and **[-1, 1]** respectively to prevent device damage.

## Hardware Setup

1. Connect the haptic device to your PC using an **Ethernet cable**

## Installation & Usage

### Build the SDK

Follow the [Setup.md](Setup.md) to setup the workspace.

Navigate to your SDK installation directory and build the workspace:
```bash
cd ~/haptic
colcon build
source install/setup.bash
```

### Launch the Haptic Node

Start the haptic interface node:
```bash
ros2 run haptic_pkg haptic_node
```

## Usage Examples

### Reading Haptic Data

**From Terminal:**
```bash
ros2 topic echo /hap/motion_data
```

### Sending Force Feedback

**From Terminal:**
```bash
# Apply 30N force in X-direction at 10Hz
ros2 topic pub -r 10 /hap/force_data haptic_pkg/msg/WriteData "{force_data: [30.0, 0.0, 0.0, 0.0, 0.0, 0.0]}"
```

## Topics

| Topic Name | Message Type | Direction | Description |
|------------|-------------|-----------|-------------|
| `/hap/motion_data` | `haptic_pkg/msg/MotionData` | Published | Haptic device state (position, velocity, buttons) |
| `/hap/force_data` | `haptic_pkg/msg/ForceData` | Subscribed | Force feedback commands |

## Safety Notes

- **Always** validate force values are within **[-40, 40]** and torque values within **[-1, 1]** before publishing
- Test with low forces initially to understand device behavior

## Troubleshooting

### Connection Issues
- Verify Ethernet cable connection

### No Data Received
- Confirm `haptic_node` is running: `ros2 node list`
- Check topic availability: `ros2 topic list`
- Verify device power and initialization

### Force Feedback Not Working
- Ensure forces are within [-40, 40] range, and troque within the range [-1, 1].
- For higher values of force device may turn off and restart
- Verify correct topic name and message format