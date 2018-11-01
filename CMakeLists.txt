cmake_minimum_required(VERSION 3.8)
project(algorithms)
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

set(SRC
  src/bitwise.cpp
  src/array.cpp)
set(TEST
  test/main.cpp
  test/bitwise_tests.cpp
  test/array_tests.cpp)

# the executable target for the unit-tests
add_executable(${PROJECT_NAME}_test ${SRC} ${TEST})
target_include_directories(${PROJECT_NAME}_test PRIVATE ${GTEST_INCLUDE_DIRS} PRIVATE src/)
target_link_libraries(${PROJECT_NAME}_test ${GTEST_BOTH_LIBRARIES} Threads::Threads)
target_compile_features(${PROJECT_NAME}_test PRIVATE cxx_std_17)

# the target to run the tests
include(CTest)
add_test(NAME TestAll COMMAND ${PROJECT_NAME}_test)
