# English assistant

An English learning app (64bit)

Get specific article from [CNN news](https://edition.cnn.com/)

Provide an simple UI to assist learning English

## Build for Windows

### 0. Install needed tools & set environment path

- GCC (>9.3.0): https://www.mingw-w64.org/downloads/

- Ninja (1.10.0): https://ninja-build.org/

- CMake (=3.21.3): https://cmake.org/

- Qt (=5.15.2): https://www.qt.io

- JDK (=11.0.2): https://jdk.java.net/archive/

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

## Build for Linux (libjvm.so not working yet)

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
sudo apt install openjdk-11-jdk
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

- openssl: https://www.openssl.org/source/ ([DLL](https://slproweb.com/products/Win32OpenSSL.html))

- Qt: https://www.qt.io/
