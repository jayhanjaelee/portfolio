cmake_minimum_required(VERSION 3.14)
project(app VERSION 1.0.0 LANGUAGES C)

include(FetchContent)

FetchContent_Declare(
  ecewo
  GIT_REPOSITORY https://github.com/savashn/ecewo.git
  GIT_TAG v3.1.1
)

FetchContent_MakeAvailable(ecewo)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)
