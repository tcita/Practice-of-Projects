## English assistant

An English learning app.

## How to build

### 0. Install needed tools & set environment path.

- GCC: https://www.mingw-w64.org/downloads/

- Ninja: https://ninja-build.org/

- CMake: https://cmake.org/

- Qt(v5.12.12): https://www.qt.io

### 1. Go to build directory.

cd <PROJECT_ROOT_DIR>/ui/build/windows

### 2. Generate build system files

cmake ../.. -G "Ninja"

### 3. Build

cmake --build .

## Library used

- nlohmann-json (embedded): https://github.com/nlohmann/json

- Qt: https://www.qt.io/

- Google translate: https://translate.googleapis.com/translate_a/single?client=gtx&sl=auto&tl=en-US&dt=t&q=helloworld
