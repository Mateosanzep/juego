# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Millonario_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Millonario_autogen.dir\\ParseCache.txt"
  "Millonario_autogen"
  )
endif()
