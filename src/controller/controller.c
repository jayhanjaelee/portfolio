/**
 * @file controller.c
 * @author Hanjae Lee (mail@hanjaelee.com)
 * @date 2026-02-01 14:06
 */

#define VIEWS_DIR "../views"

#include <stdio.h>

#include "controller.h"
#include "file_handler.h"

void index_controller(Req *req, Res *res) {
    // 파일 읽기
    char filename[1024];
    snprintf(filename, sizeof(filename), "%s/%s", VIEWS_DIR, "index.html");
    const char *html_content = read_file(filename);
    send_html(res, OK, html_content);
}

void hello_world(Req *req, Res *res) {
    send_html(res, OK, "Hello, World!\n");
}
