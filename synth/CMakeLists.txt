cmake_minimum_required(VERSION 3.12)

enable_testing()

if(NOT DEFINED ENV{ICSC_HOME})
  message(FATAL_ERROR "ICSC_HOME is not defined")
endif()

project(interpolator_synth)

find_package(SVC REQUIRED)

set(CMAKE_CXX_STANDARD 20)

add_executable(interpolator_synth
  synth_main.cpp
  ../Interpolation/Interpolator.cpp
)

target_include_directories(interpolator_synth PUBLIC
  ../Interpolation
)

svc_target(interpolator_synth INIT_LOCAL_VARS ELAB_TOP tb.dut_inst)
