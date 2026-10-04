project(lab1 LANGUAGES CXX)

set(exe_name ${PROJECT_NAME})
set(test_name test)

add_library(corelib OBJECT BigInt.h BigInt.cpp)
target_include_directories(corelib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(${exe_name} main.cpp)
target_link_libraries(${exe_name} corelib)

add_executable(${test_name}
        test/test_bi_constructors.cpp
        test/test_bi_output.cpp
        test/test_bi_operators.cpp
)
target_link_libraries(${test_name} gtest_main corelib)
