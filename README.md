# about

An English learning app

Get specific article from [CNN news](https://edition.cnn.com/)

Provide a simple gui to assist learning English

# setup building environment

- install [msys2](https://www.msys2.org/)

- add msys2 to environment path, or set it temporary via:

```
set PATH=C:\msys64\ucrt64\bin;C:\msys64\usr\bin;%PATH%
```

- install gcc, ninja, cmake, qt6-static

```
pacman -S mingw-w64-ucrt-x86_64-gcc
pacman -S mingw-w64-ucrt-x86_64-ninja
pacman -S mingw-w64-ucrt-x86_64-cmake
pacman -S mingw-w64-ucrt-x86_64-qt6-static
```

- install [openjdk(>17.0.7)](https://adoptium.net/)

  note: environment path for "bin" & "server" directory is needed

# build

- configure the build

```
cmake -Bbuild -GNinja -DCMAKE_BUILD_TYPE=Release
```

- build the project

```
cmake --build build
```
