cmake_minimum_required(VERSION 3.10)
project(CaisseDeChampagne C)

set(CMAKE_C_STANDARD 17)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

include(CPack)
include(CTest)
enable_testing()

find_package (SQLite3 REQUIRED)
if (SQLITE3_FOUND)
    message(STATUS "SQLite3 found")
else(SQLITE3_FOUND)
    message(FATAL_ERROR "SQLite3 is required")
endif (SQLITE3_FOUND)

find_package(SDL2 REQUIRED)
if (SDL2_FOUND)
    message(STATUS "SDL2 found")
else(SDL2_FOUND)
    message(FATAL_ERROR "SDL2 is required")
endif (SDL2_FOUND)

include_directories(${SDL2_INCLUDE_DIRS} ${SQLITE3_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} src/main.c)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SQLITE3_LIBRARIES} -lmingw32 -lSDL2main -lSDL2 -lsqlite3)
