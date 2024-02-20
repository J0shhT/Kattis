@echo off

:: get problem name
if not [%1]==[] set problemname=%1
if [%1]==[] set /p problemname="Name of problem: "

if not exist "problems/%problemname%" mkdir "problems/%problemname%"

:: make link to website
if not exist "problems/%problemname%/kattis.bat" echo start https://open.kattis.com/problems/%problemname%> problems/%problemname%/kattis.bat

:: make base file
if not exist "problems/%problemname%/main.cpp" (
	echo #include ^<iostream^>>> problems/%problemname%/main.cpp
	echo:>> problems/%problemname%/main.cpp
	echo int main^(^)>> problems/%problemname%/main.cpp
	echo {>> problems/%problemname%/main.cpp
	echo.	std::ios::sync_with_stdio^(false^)^;>> problems/%problemname%/main.cpp
	echo.	std::cin.tie^(nullptr^)^;>> problems/%problemname%/main.cpp
	echo }>> problems/%problemname%/main.cpp
)

:: make build file
if not exist "problems/%problemname%/build.bat" (
	echo g++ -g -O2 -std=gnu++17 -static main.cpp -o %problemname%> problems/%problemname%/build.bat
	echo pause>> problems/%problemname%/build.bat
)

:: make run file
if not exist "problems/%problemname%/run.bat" (
	echo %problemname%.exe>> problems/%problemname%/run.bat
	echo pause>> problems/%problemname%/run.bat
)

:: make run with input file
if not exist "problems/%problemname%/run-with-input.bat" (
	echo %problemname%.exe ^< input.txt>> problems/%problemname%/run-with-input.bat
	echo pause>> problems/%problemname%/run-with-input.bat
)

:: make input file
if not exist "problems/%problemname%/input.txt" echo:> problems/%problemname%/input.txt

pause
