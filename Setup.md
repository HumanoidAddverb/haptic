# Haptic ROS2 Workspace Setup

This guide walks you through setting up the Haptic ROS2 workspace and building the project.

---

## Prerequisites

Ensure the following are installed:

- ROS2
- colcon build tools
- Git

---

## Setup Steps

### 1. Clone the Repository

```bash
git clone git@github.com:HumanoidAddverb/haptic.git
cd haptic
```

---

### 2. Install Backend to System Path

Copy the `haptic_backend` directory to `/opt/addverb/`:

```bash
sudo mkdir -p /opt/addverb/
sudo cp -r haptic_backend /opt/addverb/
```

> Ensure the folder name is correct (`haptic_backend`).

---

### 3. Build the Workspace

```bash
source /opt/ros/<your_ros2_distro>/setup.bash
colcon build
```

---

### 4. Source the Workspace

```bash
source install/setup.bash
```

---

## Setup Complete

You are now ready to use the Haptic ROS2 workspace. Follow [README.md](README.md)

---

## Troubleshooting

### Build Issues

Clean and rebuild:

```bash
rm -rf build/ install/ log/
colcon build
```

---

### Permission Issues

```bash
sudo chmod -R 755 /opt/addverb/
```

---

## Notes

- Do not run `colcon build` with `sudo`
- Ensure correct ROS2 distro is sourced
- Verify paths if workspace structure is modified