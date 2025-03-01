#ifndef HTTP_PARSER_H
#define HTTP_PARSER_H

typedef enum HttpMethod {
    GET,
    HEAD,
    POST,
    PUT,
    DELETE,
    CONNECT,
    OPTIONS,
    TRACE
} HttpMethod;

typedef enum HttpVersion { HTTP_0_9, HTTP_1_0, HTTP_1_1, HTTP_2, HTTP_3 } HttpVersion;

typedef struct HttpRequest {
    HttpMethod method;
    char *uri;
    HttpVersion version;

    char **headers;
    char *body;
} HttpRequest;

void parse_request_line(HttpRequest *r, char *raw_line);
HttpRequest *parse_http_request(char *raw_r);

#endif
