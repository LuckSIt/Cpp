# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\widgets_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\widgets_autogen.dir\\ParseCache.txt"
  "widgets_autogen"
  )
endif()
