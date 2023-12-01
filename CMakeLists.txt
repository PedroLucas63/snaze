cmake_minimum_required(VERSION 3.5.0)
project(
  snaze
  VERSION 0.1
  LANGUAGES C CXX)

include(CTest)
enable_testing()

configure_file(config/SnazeConfig.hpp.in SnazeConfig.hpp)
include_directories(
  snaze
  PUBLIC
  "${PROJECT_BINARY_DIR}"
  src/models
  src/models/players
  src/utils
  src/controller
  src/libs/cli
  src/libs/format
  src/view)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")

add_executable(
  snaze
  src/main.cpp
  src/models/players/Random.cpp
  src/models/Fruit.cpp
  src/models/Game.cpp
  src/models/Player.cpp
  src/models/players/Random.cpp
  src/models/players/Greedy.cpp
  src/models/Scene.cpp
  src/models/Snake.cpp
  src/utils/Element.cpp
  src/utils/Position.cpp
  src/utils/Side.cpp
  src/view/View.cpp
  src/controller/GameController.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
