cmake_minimum_required(VERSION 3.10)
project(CaisseDeChampagne C)

set(CMAKE_C_STANDARD 17)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

include(CPack)
include(CTest)
enable_testing()

find_package (SQLite3)
find_package(SDL2 REQUIRED)

include_directories(${SQLITE3_INCLUDE_DIRS} ${SDL2_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} main.c)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SQLITE3_LIBRARIES} -lmingw32 -lSDL2main -lSDL2)
