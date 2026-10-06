@echo off

echo =====================================
echo [Build byte pool]
echo -------------------------------------

:: Check if the build folder has already been configured by CMake
if not exist "build\CMakeCache.txt" (
    echo [INFO] CMakeCache.txt not found. Configuring project for Visual Studio 2022...
    
    :: Generate Visual Studio 17 2022 project files for x64 architecture
    cmake -G "Visual Studio 17 2022" -A x64 -B build -S .
) else (
    echo [INFO] Project already configured. Skipping CMake configuration.
)

:: Build the project using the generated solution files
echo [INFO] Compiling Debug target...
cmake --build build --config Debug
