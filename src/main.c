#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    bool lightline = true;

    while ((nread = getline(&line, &len, stdin)) != -1) {
        fprintf(stdout, "%s%s%s", lightline ? "\x1b[37m":"\x1b[90m", line, "\x1b[0m");
        lightline = !lightline;
    }

    free(line);
    exit(EXIT_SUCCESS);
}
