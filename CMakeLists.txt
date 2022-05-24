cmake_minimum_required(VERSION 3.0.0)
project(origem_ps VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(origem_ps main.cpp src/libs/bateria.cpp src/libs/cp.cpp src/libs/etb.cpp src/libs/moto.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
