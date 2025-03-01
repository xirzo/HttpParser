cmake_minimum_required(VERSION 3.31.4)

project(
  http_parser_bin
  VERSION 0.1.0
  DESCRIPTION "Simple http parser made for recreational purposes"
  LANGUAGES C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(GNUInstallDirs)

add_subdirectory(lib)

option(HTTP_PARSER_BUILD_EXAMPLES "Build example binaries" OFF)
option(HTTP_PARSER_BUILD_TESTS "Build tests" OFF)

if(HTTP_PARSER_BUILD_EXAMPLES)
  add_subdirectory(bin)
endif()

if(HTTP_PARSER_BUILD_TESTS)
  add_subdirectory(tests)
endif()

if(NOT TARGET uninstall)
  configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake" IMMEDIATE @ONLY)

  add_custom_target(
    uninstall COMMAND ${CMAKE_COMMAND} -P
                      ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
endif()
