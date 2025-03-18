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

typedef struct HttpHeader
{
    char *name;
    char *value;
    struct HttpHeader *next;
} HttpHeader;

typedef struct HttpRequest
{
    HttpMethod method;
    char *uri;
    HttpVersion version;
    size_t number_of_headers;
    char **headers;
    char *body;
} HttpRequest;

/*
 * Should not be used directly, will be made private later
 */
void initHttpRequest(HttpRequest **r);
void freeHttpRequest(HttpRequest *r);
/*
 * Should not be used directly, will be made private later
 */
void parseRequestLine(HttpRequest *r, const char *raw);
void parseHeaders(HttpRequest *r, const char *raw);

HttpRequest *parseHttpRequets(const char *raw_r);

#endif
