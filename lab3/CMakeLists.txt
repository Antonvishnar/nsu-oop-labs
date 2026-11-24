project(lab3 LANGUAGES CXX)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "*.cpp" "*.h")
add_executable(lab3 ${SOURCES})

set(exe_name ${PROJECT_NAME})

