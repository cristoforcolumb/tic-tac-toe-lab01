@echo off
setlocal
cd /d "%~dp0"
call build.bat
if errorlevel 1 (
    pause
    exit /b 1
)
build\tic_tac_toe.exe
set "GAME_EXIT_CODE=%errorlevel%"
echo.
pause
exit /b %GAME_EXIT_CODE%
