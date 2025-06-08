#ifndef PLUGIN_API_H
#define PLUGIN_API_H

typedef void (*init_fn_t)(void);
typedef void (*shutdown_fn_t)(void);
typedef void (*hello_fn_t)(const char *);

typedef struct {
  init_fn_t init;
  shutdown_fn_t shutdown;
  hello_fn_t hello;
} plugin_api_t;

plugin_api_t load_plugin_api(const char *plugin_path);

#endif
