cmake_minimum_required(VERSION 3.28)
set(PROJECT ShootEmUp)
project(${PROJECT} LANGUAGES CXX)

set(SOURCE_FILES src/bullets.cpp)
set(HEADER_FILES src/bullets.hpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(${PROJECT} ${HEADER_FILES} ${SOURCE_FILES} src/main.cpp)
target_link_libraries(${PROJECT} PRIVATE SFML::Graphics)

# Clang
find_program(CLANG_FORMAT "clang-format")
if (CLANG_FORMAT)
  unset(SOURCE_FILES_PATHS)
  foreach(SOURCE_FILE ${HEADER_FILES} ${SOURCE_FILES} src/main.cpp)
    get_source_file_property(WHERE ${SOURCE_FILE} LOCATION)
    set(SOURCE_FILES_PATHS ${SOURCE_FILES_PATHS} ${WHERE})
  endforeach()
  add_custom_target(
  ClangFormat
  COMMAND ${CLANG_FORMAT}
  -i
  -style=file
  ${SOURCE_FILES_PATHS})
  add_dependencies(${PROJECT} ClangFormat)
endif()

# Compiler Settings
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  target_compile_options(${PROJECT} PRIVATE /W4 /permissive-)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  target_compile_options(${PROJECT} PRIVATE -Wall -Wextra -pedantic)
  #target_compile_options(${PROJECT} PRIVATE -O3)
endif()

