/**
 * @file main.c
 * @author Hanjae Lee (mail@hanjaelee.com)
 * @date 2026-01-28 23:52
 */

#define PORT 8100

#include <stdio.h>

#include "ecewo.h"
#include "file_handler.h"
// #include "controller.h"

void hello_world(Req *req, Res *res) {
    // 파일 읽기
    char *filename = "views/index.html";
    char *html_content = read_file(filename);

    send_html(res, OK, html_content);
}

int main(void) {
    if (server_init() != 0) {
        fprintf(stderr, "Failed to initialize server\n");
        return -1;
    }

    get("/", hello_world);

    if (server_listen(PORT) != 0) {
        fprintf(stderr, "Failed to start server\n");
        return -1;
    }

    server_run();
    return 0;
}
