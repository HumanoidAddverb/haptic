#ifndef ERROR_CODES_H_
#define ERROR_CODES_H_

enum class Errors {
  
  /// @brief UI Errors
  BadAllocation,
  UICommandSettingFailure,
  /// @brief Application
  AppInitializationFailed,
  AppStopped,
  /// @brief State Machine
  StateContextCreationFailed,
  /// @brief GLFW
  GlfwInitializationFailed,
  GlfwWindowCreationFailed,
  GlfwCallbacksFailed,
  /// @brief OpenGL
  GladInitializationFailed,
  VertexShaderFileInvalid,
  FragmentShaderFileInvalid,
  ShaderCompilationFailed,
  ShaderProgramCreationFailed,
  ProgramIdInvalid,
  TextureLoadFailed,
  /// @brief Simulator
  PhysxFoundationCreationFailed,
  PhysxPhysicsCreationFailed,
  PhysxSceneCreationFailed,
  MeshCookingFailed,
  PhysxActorIsNull,
  ObjectNotSelected,
  TimeoutReached,
  MouseRayCastFailed,
  SceneRenderingFailed,
  /// @brief Robot Errors
  DeviceSetupFailed,
  SocketSendFailure,
  SocketConnectFailure,
  HapticSafetySetupFailed,
  DeviceLoopError,
  AppStateTransitionFailed,
  HapticEngineSetupFailed,
  AppPerformActionFailed,
  AppStateRunFailed,
  ReadMotionDataFailed,
  ControlContextSetupFailed,
  EngineControllerSetupFailed,
  EngineKinematicsSetupFailed,
  EngineLowerLevelSetupFailed,
  EngineLowerLevelStartFailed,
  EngineWorkerReadFailed,
  EngineWorkerControllerFailed,
  EngineWorkerWriteFailed,
  EngineWorkerWriteSafetyFailed,
  EngineWorkerLLFailed,
  EngineWorkerReadSafetyFailed,
  SigpipeError

};

#endif
