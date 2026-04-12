@echo off
echo Compiling Chronos...

gcc -o chronos main.c events.c

if %errorlevel% neq 0 (
    echo Compilation failed!
) else (
    echo Compilation successful!
    echo Running program...
    chronos.exe
)

pause