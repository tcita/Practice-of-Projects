## English assistant

An English learning app

Get specific artical from CNN(https://edition.cnn.com/)

Provide an simple UI to assist learning English

## Build for Windows

### 0. Install needed tools & set environment path

- GCC: https://www.mingw-w64.org/downloads/

- Ninja: https://ninja-build.org/

- CMake: https://cmake.org/

- Qt(v5.15.2): https://www.qt.io

- JDK(>1.8): https://jdk.java.net/17/
  Note: Environment path for "bin" & "server" directory is needed

### 1. Go to ui directory

`cd ui`

### 2. Generate build system files

`cmake . -B build -G "Ninja"`

### 3. Build

`cmake --build build`

## Build for Linux (tested on KDE Neon)

### 0. Install needed tools

```bash
# install gcc
sudo apt install g++

# install ninja
sudo apt install ninja

# install cmake
sudo apt install cmake

# install Qt lib & tools
sudo apt install qttools5-dev

# install jdk & tools
sudo apt install openjdk-17-jdk

```

### 1. Go to ui directory

`cd ui`

### 2. Generate build system files

`cmake . -B build -G "Ninja"`

### 3. Build

`cmake --build build`


## Library used

- nlohmann-json (embedded): https://github.com/nlohmann/json

- Qt: https://www.qt.io/

- Google translate: https://translate.googleapis.com/translate_a/single?client=gtx&sl=auto&tl=en-US&dt=t&q=helloworld

- openjdk: https://openjdk.java.net/
