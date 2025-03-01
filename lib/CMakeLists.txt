add_library(http_parser STATIC ${CMAKE_CURRENT_SOURCE_DIR}/src/http_parser.c)

add_library(HttpParser::HttpParser ALIAS http_parser)

target_include_directories(
  http_parser PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
                     $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

set_target_properties(http_parser PROPERTIES VERSION ${PROJECT_VERSION}
                                             SOVERSION ${PROJECT_VERSION_MAJOR})

install(
  TARGETS http_parser
  EXPORT HttpParserTargets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  INCLUDES
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(
  DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  FILES_MATCHING
  PATTERN "*.h")

install(
  EXPORT HttpParserTargets
  FILE HttpParserTargets.cmake
  NAMESPACE HttpParser::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/HttpParser)
