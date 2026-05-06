# CMake generated Testfile for 
# Source directory: /home/yaroslav/Programming/SystemC/Interpolation/synth
# Build directory: /home/yaroslav/Programming/SystemC/Interpolation/synth/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(interpolator_synth_BUILD "/usr/bin/cmake" "--build" "/home/yaroslav/Programming/SystemC/Interpolation/synth/build" "--target" "interpolator_synth_sctool")
set_tests_properties(interpolator_synth_BUILD PROPERTIES  _BACKTRACE_TRIPLES "/home/yaroslav/Programming/SystemC/tools/icsc-install/lib/cmake/SVC/svc_target.cmake;237;add_test;/home/yaroslav/Programming/SystemC/Interpolation/synth/CMakeLists.txt;24;svc_target;/home/yaroslav/Programming/SystemC/Interpolation/synth/CMakeLists.txt;0;")
add_test(interpolator_synth_SYN "/home/yaroslav/Programming/SystemC/Interpolation/synth/build/interpolator_synth_sctool")
set_tests_properties(interpolator_synth_SYN PROPERTIES  DEPENDS "interpolator_synth_BUILD" WILL_FAIL "FALSE" _BACKTRACE_TRIPLES "/home/yaroslav/Programming/SystemC/tools/icsc-install/lib/cmake/SVC/svc_target.cmake;242;add_test;/home/yaroslav/Programming/SystemC/Interpolation/synth/CMakeLists.txt;24;svc_target;/home/yaroslav/Programming/SystemC/Interpolation/synth/CMakeLists.txt;0;")
