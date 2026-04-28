#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "haptic_backend::pc_queue" for configuration ""
set_property(TARGET haptic_backend::pc_queue APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(haptic_backend::pc_queue PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "/opt/addverb/haptic_backend/lib/libpc_queue.so"
  IMPORTED_SONAME_NOCONFIG "libpc_queue.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS haptic_backend::pc_queue )
list(APPEND _IMPORT_CHECK_FILES_FOR_haptic_backend::pc_queue "/opt/addverb/haptic_backend/lib/libpc_queue.so" )

# Import target "haptic_backend::logger_new" for configuration ""
set_property(TARGET haptic_backend::logger_new APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(haptic_backend::logger_new PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "/opt/addverb/haptic_backend/lib/liblogger_new.so"
  IMPORTED_SONAME_NOCONFIG "liblogger_new.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS haptic_backend::logger_new )
list(APPEND _IMPORT_CHECK_FILES_FOR_haptic_backend::logger_new "/opt/addverb/haptic_backend/lib/liblogger_new.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
