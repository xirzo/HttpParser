#include "http_parser.h"

#include <stdlib.h>
#include <string.h>

void parse_request_line(HttpRequest *r, char *raw_line) {
    char *ptr;
    __strtok_r(raw_line, " ", &ptr);
}

HttpRequest *parse_http_request(char *raw_request) {
    HttpRequest *r = malloc(sizeof(*r));

    return r;
}
