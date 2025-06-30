# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\QtCharts_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\QtCharts_autogen.dir\\ParseCache.txt"
  "QtCharts_autogen"
  )
endif()
