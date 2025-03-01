add_executable(http_parser_example main.c)

target_link_libraries(http_parser_example PRIVATE HttpParser::HttpParser)
