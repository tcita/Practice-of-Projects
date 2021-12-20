# English assistant
An English learning app.

# How to build (There are many ways to build, this is just an example)
0. Install needed tools, skip this step if you have already installed them.
-GCC: https://www.mingw-w64.org/downloads/
-Ninja: https://ninja-build.org/ 
-CMake: https://cmake.org/
-Qt: https://www.qt.io/download-qt-installer?utm_referrer=https%3A%2F%2Fwww.qt.io%2Fdownload-open-source%3Futm_referrer%3Dhttps%253A%252F%252Fwww.qt.io%252F

1. Go to build directory.
  cd build/linux

2. Generate build system files
  cmake ../.. -G "Ninja"

3. Build
  cmake --build .

# Library used
-nlohmann-json (embedded): https://github.com/nlohmann/json
-Qt: https://www.qt.io/
