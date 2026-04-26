# cpp-mastery

Structured C++ practice following the LearnCPP syllabus, built as preparation for high-performance computing and systems-level work.

## Purpose

* Rebuild solid C++ fundamentals from first principles
* Practice correct, idiomatic usage (not just “working code”)
* Create a reliable base for concurrency, performance, and modern C++

This repository is **deliberate practice**, not polished projects.

---

## Structure

Each chapter from LearnCPP is mapped to its own directory:

```
/ch16_vectors
/ch17_arrays
...
```

Inside each:

* `*.cpp` → exercises / quizzes / implementations
* `*.hpp` → supporting code where needed

Root:

* `CMakeLists.txt` → build configuration
* `.clang-format` → formatting rules

---

## Build & Run

**Environment:** WSL2 (Linux)
**Build system:** CMake

```bash
mkdir build
cd build
cmake ..
make
./<executable>
```

Executables depend on the target defined in `CMakeLists.txt`.

---

## Approach

* Small, focused programs per concept
* Repetition of tricky areas (memory, references, value semantics)
* Minimal abstraction unless fully understood
* Prefer explicitness over convenience

---

## Scope

Covers:

* Core language fundamentals
* Memory and data structures
* Basic problem solving via exercises

Prepares for:

* Modern C++ (C++17/20)
* Concurrency
* Performance-oriented design

---

## Notes

* Code may be rewritten frequently as understanding improves
* Some files intentionally explore edge cases or incorrect approaches

---

## Context

This work supports:

* Preparation for postgraduate study in high-performance computing
* Application to C++-focused opportunities (e.g. CppCon scholarship)

---
