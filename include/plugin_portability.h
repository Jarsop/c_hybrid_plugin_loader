#ifndef PLUGIN_PORTABILITY_H
#define PLUGIN_PORTABILITY_H

#if defined(__GNUC__) || defined(__clang__)
  #define WEAK_ATTR __attribute__((weak))
#else
  #define WEAK_ATTR
#endif

#endif
