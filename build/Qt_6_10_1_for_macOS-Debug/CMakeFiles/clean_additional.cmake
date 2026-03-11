# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/PizzaGenie_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/PizzaGenie_autogen.dir/ParseCache.txt"
  "PizzaGenie_autogen"
  )
endif()
