@echo off

echo === Assembling assembly file ===
nasm -f win64 normalize.asm -o normalize.obj
if errorlevel 1 goto :error

echo === Compiling main.c ===
gcc -c main.c -o main.obj -m64
if errorlevel 1 goto :error

echo === Compiling benchmark.c ===
gcc -c benchmark.c -o benchmark.obj -m64
if errorlevel 1 goto :error

echo === Linking main program ===
gcc main.obj normalize.obj -o program.exe -m64
if errorlevel 1 goto :error

echo === Linking benchmark program ===
gcc benchmark.obj normalize.obj -o benchmark.exe -m64
if errorlevel 1 goto :error

echo === Executables created successfully ===
goto :end

:error
echo Build failed!
:end
