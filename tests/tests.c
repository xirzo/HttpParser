#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "http_parser.h"

char raw_request[] =
    "GET /index.html HTTP/1.1\r\n"
    "Host: localhost:5000\r\n"
    "User-Agent: curl/7.68.0\r\n"
    "\r\n";

void test_parse_request_line() {
    char raw_request_line[] = "GET /index.html HTTP/1.1\r\n";
    HttpRequest *r;
    init_http_request(&r);

    parse_request_line(r, raw_request_line);

    printf("%u\n", r->method);
    printf("%s\n", r->uri);
    printf("%u\n", r->version);

    assert(r->method == HTTP_GET);
    assert(strcmp(r->uri, "/index.html") == 0);
    assert(r->version == HTTP_1_1);

    free(r);
}

int main() {
    test_parse_request_line();
    printf("All tests passed!\n");
    return EXIT_SUCCESS;
}
