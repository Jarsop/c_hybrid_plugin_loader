#include <plugin_api.h>

int main() {
  plugin_api_t plugin = load_plugin_api("./libdynamic_plugin.so");

  plugin.init();
  plugin.hello("Jarsop");
  plugin.shutdown();

  return 0;
}
