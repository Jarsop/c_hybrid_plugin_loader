cmake_minimum_required(VERSION 3.15)
project(c_hybrid_plugon_loader C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(dynamic_plugin SHARED src/dynamic_plugin.c)

add_library(plugin_defaults OBJECT
    src/plugin_defaults.c
    src/plugin_loader.c
)
target_include_directories(plugin_defaults PUBLIC include)

add_library(plugin_overrides OBJECT
    src/plugin_overrides.c
)
target_include_directories(plugin_overrides PUBLIC include)

add_executable(default src/main.c)
target_sources(default PRIVATE $<TARGET_OBJECTS:plugin_defaults>)
target_include_directories(default PUBLIC include)

add_executable(override src/main.c)
target_sources(override PRIVATE
    $<TARGET_OBJECTS:plugin_defaults>
    $<TARGET_OBJECTS:plugin_overrides>
)
target_include_directories(override PUBLIC include)

if(UNIX)
    target_link_libraries(default PRIVATE dl)
    target_link_libraries(override PRIVATE dl)
endif()
