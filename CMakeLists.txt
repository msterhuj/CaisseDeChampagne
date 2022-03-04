cmake_minimum_required(VERSION 3.1.0)
project(gabin VERSION 0.1.0)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED true)


include(CTest)
enable_testing()

find_package(SDL2 REQUIRED)
find_package(SDL2_TTF REQUIRED)

find_package(sqlite3 REQUIRED)

if (SDL2_FOUND)
    message("sdl ok")
endif()

include_directories(${SDL2_IMAGE_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS})

add_executable(gabin src/main.c)

target_link_libraries(gabin SQLite::SQLite3 ${SDL2_LIBRARY} ${SDL2_TTF_LIBRARIES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)