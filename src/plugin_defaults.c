#include <plugin_portability.h>
#include <stdio.h>

void WEAK_ATTR default_init(void) { printf("[default] init()\n"); }

void WEAK_ATTR default_shutdown(void) { printf("[default] shutdown()\n"); }

void WEAK_ATTR default_hello(const char *name) {
  printf("[default] hello(%s)\n", name);
}
