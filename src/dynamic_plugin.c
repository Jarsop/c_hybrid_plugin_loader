#include <stdio.h>

void default_init(void) { printf("[dynamic] init()\n"); }

void default_hello(const char *name) { printf("[dynamic] hello(%s)\n", name); }
