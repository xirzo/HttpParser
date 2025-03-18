#include <stdlib.h>

#include "http_parser.h"

int main(void) {
    char request[] = "GET /index.html HTTP/1.1\r\n";
    HttpRequest *req;
    initHttpRequest(&req);

    parseRequestLine(req, request);

    // Future versions will support full request parsing
    // req = parse_http_request(request);

    freeHttpRequest(req);
    return EXIT_SUCCESS;
}
