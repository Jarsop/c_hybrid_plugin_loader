# Hybrid Plugin Loader (Weak + Dynamic Fallback)

**Purpose**  
Demonstrates a portable plugin system in C that:

- Provides weak-based default implementations where supported,
- Loads dynamic overrides at runtime via `dlsym`/`GetProcAddress`,
- Supports full portability (Linux, macOS, Windows, MSVC/MinGW).

## 🔧 Build & Run

```bash
cmake -B build -S .
cmake --build build
```

### Run with defaults

```bash
./build/default
# Output:
#   [loader] No plugin loaded: ./libdynamic_plugin.so
#   [default] init()
#   [default] hello(Jarsop)
#   [default] shutdown()
```

### Run with override

```bash
./build/override
# Output:
#   [loader] No plugin loaded: ./libdynamic_plugin.so
#   [override] init()
#   [override] hello(Jarsop)
#   [default] shutdown()
```

### Run with dynamic plugin

```bash
cd build
./default
# Output:
#   [dynamic] init()
#   [dynamic] hello(Jarsop)
#   [default] shutdown()
#
# Or
#
./override
# Output:
#   [dynamic] init()
#   [dynamic] hello(Jarsop)
#   [default] shutdown()
```

## License

MIT License
