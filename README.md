## English assistant

An English learning app (64bit)

Get specific artical from [CNN](https://edition.cnn.com/)

Provide an simple UI to assist learning English

## Build for Windows

### 0. Install needed tools & set environment path

- GCC: https://www.mingw-w64.org/downloads/

- Ninja: https://ninja-build.org/

- CMake: https://cmake.org/

- Qt(v5.15.2): https://www.qt.io

- JDK(>=8): https://jdk.java.net/17/

  Note: Environment path for "bin" & "server" directory is needed

### 1. Create and go to build directory

```cmd
mkdir build
cd build
```

### 2. Generate build system files

`cmake .. -G "Ninja"`

### 3. Build

`cmake --build .`

## Build for Linux (tested on KDE Neon)

### 0. Install needed tools

```sh
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

### 1. Create and go to build directory

```sh
mkdir build
cd build
```

### 2. Generate build system files

`cmake .. -G "Ninja"`

### 3. Build

`cmake --build .`


## Library used

- Google translate: https://translate.googleapis.com/translate_a/single?client=gtx&sl=auto&tl=en-US&dt=t&q=helloworld

- nlohmann-json (embedded): https://github.com/nlohmann/json

- openjdk: https://openjdk.java.net/

- openssl: https://www.openssl.org/source/ [DLL](https://slproweb.com/products/Win32OpenSSL.html)

- Qt: https://www.qt.io/
