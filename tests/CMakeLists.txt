add_executable(tests tests.c)

target_link_libraries(tests PRIVATE http_parser)

add_test(NAME tests COMMAND tests)
