@echo off
setlocal
cd /d "%~dp0"
set "GAME_CXX=g++"
where g++ >nul 2>nul
if errorlevel 1 (
    if exist "C:\MinGW\bin\g++.exe" (
        set "GAME_CXX=C:\MinGW\bin\g++.exe"
        set "PATH=C:\MinGW\bin;%PATH%"
    ) else (
        echo Nu am gasit g++. Instaleaza un compilator C++ sau adauga-l in PATH.
        exit /b 1
    )
)
if not exist build mkdir build
if not exist build (
    echo Nu am putut crea directorul build.
    exit /b 1
)
"%GAME_CXX%" -std=c++11 -Wall -Wextra -Wpedantic -static -I include src\GameEngine.cpp src\Renderer.cpp src\Listener.cpp tests\tests.cpp -o build\game_tests.exe
if errorlevel 1 exit /b 1
build\game_tests.exe
exit /b %errorlevel%
