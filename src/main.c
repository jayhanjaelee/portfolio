/**
 * @file main.c
 * @author Hanjae Lee (mail@hanjaelee.com)
 * @date 2026-01-28 23:52
 */

#define PORT 8100

#include <stdio.h>

#include "ecewo.h"
#include "controller.h"

int main(void) {
    if (server_init() != 0) {
        fprintf(stderr, "Failed to initialize server\n");
        return -1;
    }

    get("/", index_controller);
    get("/hello", hello_world);

    if (server_listen(PORT) != 0) {
        fprintf(stderr, "Failed to start server\n");
        return -1;
    }

    server_run();
    return 0;
}
