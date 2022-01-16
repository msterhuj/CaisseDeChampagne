cmake_minimum_required(VERSION 3.10)
project(CaisseDeChampagne C)

set(CMAKE_C_STANDARD 99)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

include(CPack)
include(CTest)
enable_testing()

find_package (SQLite3)
include_directories(${SQLITE3_INCLUDE_DIRS})

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED gtk+-3.0)
include_directories(${GTK_INCLUDE_DIRS})
link_directories(${GTK_LIBRARY_DIRS})

add_executable(${PROJECT_NAME} main.c)
target_link_libraries(${PROJECT_NAME} ${GTK_LIBRARIES})
target_link_libraries (${PROJECT_NAME} ${SQLITE3_LIBRARIES})