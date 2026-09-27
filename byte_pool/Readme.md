
cmake -G "MinGW Makefiles" -DCMAKE_C_COMPILER="D:/mingw_gnu/bin/gcc.exe" -B build -S .
cmake --build build
.\build\byte_pool.exe

