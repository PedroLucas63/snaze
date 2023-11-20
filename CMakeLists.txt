cmake_minimum_required(VERSION 3.5.0)
project(
  Snaze
  VERSION 0.1
  LANGUAGES C CXX)

include(CTest)
enable_testing()

configure_file(config/SnazeConfig.hpp.in SnazeConfig.hpp)
include_directories(
  Snaze
  PUBLIC
  "${PROJECT_BINARY_DIR}"
  src/models
  src/utils
  src/controller
  src/libs
  src/view)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")

add_executable(
  Snaze
  src/main.cpp
  src/models/Snake.cpp
  src/models/Fruit.cpp
  src/models/Scene.cpp
  src/utils/Element.cpp
  src/utils/Side.cpp
  src/controller/GameController.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
