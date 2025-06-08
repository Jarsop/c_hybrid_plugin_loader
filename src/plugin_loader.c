#include <plugin_api.h>
#include <stdio.h>

#if defined(_WIN32)
#include <windows.h>
#define LIB_HANDLE HMODULE
#define LOAD_LIB(path) LoadLibraryA(path)
#define LOAD_SYM(lib, sym) GetProcAddress(lib, sym)
#define CLOSE_LIB(lib) FreeLibrary(lib)
#else
#include <dlfcn.h>
#define LIB_HANDLE void *
#define LOAD_LIB(path) dlopen(path, RTLD_NOW)
#define LOAD_SYM(lib, sym) dlsym(lib, sym)
#define CLOSE_LIB(lib) dlclose(lib)
#endif

extern void default_init(void);
extern void default_shutdown(void);
extern void default_hello(const char *name);

plugin_api_t load_plugin_api(const char *plugin_path) {
  plugin_api_t api = {.init = default_init,
                      .shutdown = default_shutdown,
                      .hello = default_hello};

  LIB_HANDLE handle = LOAD_LIB(plugin_path);
  if (!handle) {
    fprintf(stderr, "[loader] No plugin loaded: %s\n", plugin_path);
    return api;
  }

  void *sym;

  sym = LOAD_SYM(handle, "default_init");
  if (sym)
    api.init = (init_fn_t)sym;

  sym = LOAD_SYM(handle, "default_shutdown");
  if (sym)
    api.shutdown = (shutdown_fn_t)sym;

  sym = LOAD_SYM(handle, "default_hello");
  if (sym)
    api.hello = (hello_fn_t)sym;

  return api;
}
