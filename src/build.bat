@echo off

echo === Assembling assembly file ===
nasm -f win64 normalize.asm -o normalize.obj
if errorlevel 1 goto :error

echo === Compiling main.c ===
gcc -c main.c -o main.obj -m64
if errorlevel 1 goto :error

echo === Linking main program ===
gcc main.obj normalize.obj -o program.exe -m64
if errorlevel 1 goto :error

echo === Executable created successfully ===
goto :end

:error
echo Build failed!
:end
