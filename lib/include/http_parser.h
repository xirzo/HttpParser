#ifndef HTTP_PARSER_H
#define HTTP_PARSER_H

#include <stddef.h>

#define MAX_URI_LENGTH 256

typedef enum HttpMethod
{
    HTTP_UNDEFINED_METHOD,
    HTTP_GET,
    HTTP_HEAD,
    HTTP_POST,
    HTTP_PUT,
    HTTP_DELETE,
    HTTP_CONNECT,
    HTTP_OPTIONS,
    HTTP_TRACE,
    HTTP_UNKNOWN_METHOD,
} HttpMethod;

typedef enum HttpVersion
{
    HTTP_UNDEFINED_VERSION,
    HTTP_0_9,
    HTTP_1_0,
    HTTP_1_1,
    HTTP_2,
    HTTP_3,
    HTTP_UNKNOWN_VERSION,
} HttpVersion;

typedef struct HttpRequest
{
    HttpMethod method;
    char *uri;
    HttpVersion version;
    size_t number_of_headers;
    char **headers;
    char *body;
} HttpRequest;

void init_http_request(HttpRequest **r);
void free_http_request(HttpRequest *r);
void parse_request_line(HttpRequest *r, char *raw_line);
HttpRequest *parse_http_request(char *raw_r);

#endif
