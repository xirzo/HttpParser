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

void testParseRequestLine() {
    char raw[] = "GET /index.html HTTP/1.1\r\n";
    HttpRequest *r;
    initHttpRequest(&r);

    parseRequestLine(r, raw);

    assert(r->method == HTTP_GET);
    assert(strcmp(r->uri, "/index.html") == 0);
    assert(r->version == HTTP_1_1);

    free(r);
}

void testParseSingleHeader() {
    char raw[] = "Host: localhost:5000\r\n";
    HttpRequest *r;
    initHttpRequest(&r);

    parseHeaders(r, raw);

    assert(r->method == HTTP_GET);
    assert(strcmp(r->uri, "/index.html") == 0);
    assert(r->version == HTTP_1_1);

    free(r);
}

int main() {
    testParseRequestLine();
    testParseSingleHeader();

    printf("All tests passed!\n");
    return EXIT_SUCCESS;
}
