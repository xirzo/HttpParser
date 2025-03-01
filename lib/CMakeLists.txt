add_library(http_parser STATIC ${CMAKE_CURRENT_SOURCE_DIR}/src/http_parser.c)

target_include_directories(http_parser
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/)
