cmake_minimum_required(VERSION 3.8)
project(haptic_pkg)

cmake_policy(SET CMP0022 NEW)

# ==================================================
# Compiler Flags
# ==================================================
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# ==================================================
# ROS 2 Dependencies
# ==================================================
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# ==================================================
# Path to Installed Haptic Backend
# ==================================================
# set(HAPTIC_BACKEND_DIR /opt/addverb/haptic_backend CACHE PATH "Path to installed haptic backend")
# set(HAPTIC_BACKEND_INCLUDE_DIR ${HAPTIC_BACKEND_DIR}/include)
# set(HAPTIC_BACKEND_LIB_DIR ${HAPTIC_BACKEND_DIR}/lib)
# Define the base installation directory (user-overridable)
set(HAPTIC_BACKEND_DIR "/opt/addverb/haptic_backend"
    CACHE PATH "Base path to the installed Haptic Backend")

# Define include and lib directories derived from it
set(HAPTIC_BACKEND_INCLUDE_DIR "${HAPTIC_BACKEND_DIR}/include"
    CACHE PATH "Path to Haptic Backend include directory")

set(HAPTIC_BACKEND_LIB_DIR "${HAPTIC_BACKEND_DIR}/lib"
    CACHE PATH "Path to Haptic Backend library directory")

# ==================================================
# Find Backend Libraries
# ==================================================
file(GLOB HAPTIC_BACKEND_LIBRARIES "${HAPTIC_BACKEND_LIB_DIR}/*.so")

message(STATUS ">> Haptic backend include dir: ${HAPTIC_BACKEND_INCLUDE_DIR}")
message(STATUS ">> Haptic backend lib dir: ${HAPTIC_BACKEND_LIB_DIR}")
message(STATUS ">> Found haptic backend libs: ${HAPTIC_BACKEND_LIBRARIES}")

if(NOT HAPTIC_BACKEND_LIBRARIES)
  message(FATAL_ERROR "No haptic backend libraries found in ${HAPTIC_BACKEND_LIB_DIR}")
endif()

# Explicitly list key libraries with correct linking order
# Dependencies should be listed after libraries that depend on them
set(HAPTIC_BACKEND_LIBS
  ${HAPTIC_BACKEND_LIB_DIR}/libhaptic_builder_lib.so
  ${HAPTIC_BACKEND_LIB_DIR}/libfsm_haptic_context.so
  ${HAPTIC_BACKEND_LIB_DIR}/libfsm_states.so
  ${HAPTIC_BACKEND_LIB_DIR}/libhaptic_force_control.so
  ${HAPTIC_BACKEND_LIB_DIR}/libhaptic_engine.so
  ${HAPTIC_BACKEND_LIB_DIR}/libvisitor_utility_lib.so
  ${HAPTIC_BACKEND_LIB_DIR}/libdata_manager_lib.so
  ${HAPTIC_BACKEND_LIB_DIR}/libdata_handler_lib.so
  ${HAPTIC_BACKEND_LIB_DIR}/liblower_level.so
  ${HAPTIC_BACKEND_LIB_DIR}/libparallel_robot_lib.so
  ${HAPTIC_BACKEND_LIB_DIR}/libkd.so
  ${HAPTIC_BACKEND_LIB_DIR}/libutility_lib.so
  ${HAPTIC_BACKEND_LIB_DIR}/liberror_manager.so
  ${HAPTIC_BACKEND_LIB_DIR}/liblogger_new.so
  ${HAPTIC_BACKEND_LIB_DIR}/liblogger.so
  ${HAPTIC_BACKEND_LIB_DIR}/libtimer_lib.so
  ${HAPTIC_BACKEND_LIB_DIR}/libmoving_average.so
  ${HAPTIC_BACKEND_LIB_DIR}/libtime_derivative.so
  ${HAPTIC_BACKEND_LIB_DIR}/libsafety.so
  ${HAPTIC_BACKEND_LIB_DIR}/libcustom_exception.so
  ${HAPTIC_BACKEND_LIB_DIR}/libpc_queue.so
)

# ==================================================
# ROS 2 Message Generation
# ==================================================
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/ReadData.msg"
  "msg/WriteData.msg"
  DEPENDENCIES std_msgs
)

ament_export_dependencies(rosidl_default_runtime)

# ==================================================
# Executable Definition
# ==================================================
add_executable(haptic_node
  src/ros2_main.cpp
  src/haptic_ros2.cpp
)

# ==================================================
# Include Directories
# ==================================================
target_include_directories(haptic_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/rosidl_generator_cpp>
  $<INSTALL_INTERFACE:include>
  ${HAPTIC_BACKEND_INCLUDE_DIR}
)

# ==================================================
# Link ROS 2 Dependencies
# ==================================================
ament_target_dependencies(haptic_node
  rclcpp
  std_msgs
)

# ==================================================
# Generate message dependencies
# ==================================================
add_dependencies(haptic_node
  ${PROJECT_NAME}__cpp
)

# ==================================================
# Link Libraries
# ==================================================
rosidl_get_typesupport_target(cpp_typesupport_target
  ${PROJECT_NAME} rosidl_typesupport_cpp)

target_link_libraries(haptic_node
  "${cpp_typesupport_target}"
  -Wl,--whole-archive
  ${HAPTIC_BACKEND_LIBS}
  -Wl,--no-whole-archive
)

# ==================================================
# RPATH for Runtime Linking
# ==================================================
set_target_properties(haptic_node PROPERTIES
  BUILD_RPATH_USE_ORIGIN TRUE
  BUILD_RPATH "${HAPTIC_BACKEND_LIB_DIR}"
  INSTALL_RPATH "${HAPTIC_BACKEND_LIB_DIR}"
  BUILD_WITH_INSTALL_RPATH TRUE
)

# ==================================================
# Install Rules
# ==================================================
install(TARGETS haptic_node
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY include/
  DESTINATION include
)

# ==================================================
# Export Package
# ==================================================
install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/environment/library_path.dsv" DESTINATION share/${PROJECT_NAME}/environment)
ament_export_include_directories(include)
ament_package()