cmake_minimum_required(VERSION 3.31.4)

project(
  http_parser_bin
  DESCRIPTION "Simple http parser made for recreational purposes"
  LANGUAGES C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(lib)
add_subdirectory(bin)

add_subdirectory(tests)
