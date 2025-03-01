#include "http_parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init_http_request(HttpRequest **r) {
    *r = malloc(sizeof(HttpRequest));

    (*r)->method = HTTP_UNDEFINED_METHOD;
    (*r)->version = HTTP_UNDEFINED_VERSION;
    (*r)->number_of_headers = 0;
    (*r)->headers = NULL;
    (*r)->body = NULL;

    (*r)->uri = malloc(MAX_URI_LENGTH * sizeof(char));

    if ((*r)->uri == NULL) {
        fprintf(stderr, "Failed to allocate memory for URI\n");
        free(*r);
        exit(EXIT_FAILURE);
    }

    (*r)->uri[0] = '\0';
}

void free_http_request(HttpRequest *r) {
    if (r == NULL) {
        return;
    }

    if (r->uri != NULL) {
        free(r->uri);
    }

    if (r->headers != NULL) {
        for (size_t i = 0; i < r->number_of_headers; i++) {
            if (r->headers[i] != NULL) {
                free(r->headers[i]);
            }
        }
        free(r->headers);
    }

    if (r->body != NULL) {
        free(r->body);
    }

    free(r);
}

void parse_request_line(HttpRequest *r, char *raw_line) {
    char *token = strtok(raw_line, " ");

    if (token == NULL) {
        fprintf(stderr, "Failed to get token for http method\n");
        return;
    }

    if (strcmp(token, "GET") == 0) {
        r->method = HTTP_GET;
    } else if (strcmp(token, "HEAD") == 0) {
        r->method = HTTP_HEAD;
    } else if (strcmp(token, "POST") == 0) {
        r->method = HTTP_POST;
    } else if (strcmp(token, "PUT") == 0) {
        r->method = HTTP_PUT;
    } else if (strcmp(token, "DELETE") == 0) {
        r->method = HTTP_DELETE;
    } else if (strcmp(token, "CONNECT") == 0) {
        r->method = HTTP_CONNECT;
    } else if (strcmp(token, "OPTIONS") == 0) {
        r->method = HTTP_OPTIONS;
    } else if (strcmp(token, "TRACE") == 0) {
        r->method = HTTP_TRACE;
    } else {
        r->method = HTTP_UNKNOWN_METHOD;
    }

    token = strtok(NULL, " ");

    if (token == NULL) {
        fprintf(stderr, "Failed to get token for http uri\n");
        return;
    }

    r->uri = token;

    token = strtok(NULL, "\r\n");

    printf("%s", token);

    if (token == NULL) {
        fprintf(stderr, "Failed to get token for http version\n");
        return;
    }

    if (strcmp(token, "HTTP/0.9") == 0) {
        r->version = HTTP_0_9;
    } else if (strcmp(token, "HTTP/1.0") == 0) {
        r->version = HTTP_1_0;
    } else if (strcmp(token, "HTTP/1.1") == 0) {
        r->version = HTTP_1_1;
    } else if (strcmp(token, "HTTP/2") == 0) {
        r->version = HTTP_2;
    } else if (strcmp(token, "HTTP/3") == 0) {
        r->version = HTTP_3;
    } else {
        r->version = HTTP_UNKNOWN_VERSION;
    }
}

HttpRequest *parse_http_request(char *raw_request) {
    HttpRequest *r = malloc(sizeof(*r));

    return r;
}
