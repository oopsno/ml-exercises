cmake_minimum_required(VERSION 3.4)
project(ml_exercises)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

set(exercise_2 bin/exercise_2.cpp)
file(GLOB algo_src   src/*.cpp)
add_executable(ml_exercises_2 ${exercise_2} ${algo_src})
target_link_libraries(ml_exercises_2 armadillo)

file(GLOB utest_src   utest/*.cpp)
add_executable(ml_exercises_utest ${utest_src})
target_link_libraries(ml_exercises_utest gtest)

