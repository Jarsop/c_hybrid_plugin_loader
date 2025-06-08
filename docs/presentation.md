---
title: "Portable Hybrid Plugin Loader"
authors: ["Jean-Pierre Geslin"]
---

# 💡 Problem

We want **default plugin behavior**, overridable at runtime—ideally:

- Minimal code
- Portable across Windows/Unix
- Safe and flexible

<!-- end_slide -->

# 🚀 Approach

- Provide weak default functions
- Optionally load dynamic plugin at runtime
- Build a plugin_api vtable:
  - static fallback
  - dynamic overrides when present

<!-- end_slide -->

## 🔧 Step 1: Portable WEAK_ATTR

```c
#if defined(__GNUC__) || defined(__clang__)
  #define WEAK_ATTR __attribute__((weak))
#else
  #define WEAK_ATTR
#endif
```

<!-- end_slide -->

## 🌱 Step 2: Weak defaults

```c
void WEAK_ATTR default_init(void) { printf("[weak] init\n"); }
void WEAK_ATTR default_hello(const char* n) { printf("[weak] hello(%s)\n", n); }
```

<!-- end_slide -->

## 🔁 Step 3: Load defaults → dynamic

```c
plugin_api_t api = { default_init, ... };
if (sym = dlsym(...)) api.init = sym;
```

<!-- end_slide -->

## ✅ Behavior Matrix

| Platform     | Weak | Dynamic Plugin | Override? |
| ------------ | ---- | -------------- | --------- |
| Linux/macOS  | ✅   | ✅             | ✅        |
| Windows/MSVC | ❌   | ✅             | ✅        |

<!-- end_slide -->

## 📚 Takeaways

- Linker rules: weak vs strong
- Dynamic fallback ensures safety
- Portable & extensible design
