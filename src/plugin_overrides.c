#include <stdio.h>

void default_init(void) { printf("[override] init()\n"); }

void default_hello(const char *name) { printf("[override] hello(%s)\n", name); }
