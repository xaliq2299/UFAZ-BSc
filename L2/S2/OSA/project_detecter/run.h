#ifndef _RUN_H
#define _RUN_H

#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include "buffer.h"

Buffer run(Buffer *buf_old, char *prog, char **argv, int optind, int iExec, int bTime, char *format, int bExitCode);
// the function that executes the provided command
void print_summary(int argc, char **argv, char *prog, int optind, int bTime, char *format, int interval, int limit, int bExitCode);
// mainly for debugging

#endif