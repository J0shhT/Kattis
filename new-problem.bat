@echo off

:: get problem name
if not [%1]==[] set problemname=%1
if [%1]==[] set /p problemname="Name of problem: "

mkdir "problems/%problemname%"

:: make link to website
echo start https://open.kattis.com/problems/%problemname% > problems/%problemname%/kattis.bat

:: make base file
echo. > problems/%problemname%/main.cpp

:: make build file
echo g++ -g -O2 -std=gnu++17 -static main.cpp -o %problemname% > problems/%problemname%/build.bat
echo pause >> problems/%problemname%/build.bat

:: make run file
echo %problemname%.exe >> problems/%problemname%/run.bat
echo pause >> problems/%problemname%/run.bat

:: make run with input file
echo %problemname%.exe ^< input.txt >> problems/%problemname%/run-with-input.bat
echo pause >> problems/%problemname%/run-with-input.bat

:: make input file
echo. > problems/%problemname%/input.txt

pause
