/**
 * @file main.c
 * @author Hanjae Lee (mail@hanjaelee.com)
 * @date 2026-01-28 23:52
 */

#include "ecewo.h"
#include <stdio.h>

void hello_world(Req *req, Res *res) {
  send_text(res, OK, "Hello, World!");
}

int main(void) {
  if (server_init() != 0) {
    fprintf(stderr, "Failed to initialize server\n");
    return -1;
  }

  get("/", hello_world);

  if (server_listen(3000) != 0) {
    fprintf(stderr, "Failed to start server\n");
    return -1;
  }

  server_run();
  return 0;
}
