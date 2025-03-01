#include <stdlib.h>

#include "http_parser.h"

int main(void) {
    char request[] = "GET /index.html HTTP/1.1\r\n";
    HttpRequest *req;
    init_http_request(&req);

    parse_request_line(req, request);

    // Future versions will support full request parsing
    // req = parse_http_request(request);

    free_http_request(req);
    return EXIT_SUCCESS;
}
