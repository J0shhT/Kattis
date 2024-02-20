@echo off

:: get problem name
if not [%1]==[] set problemname=%1
if [%1]==[] set /p problemname="Name of problem: "

if not exist "problems/%problemname%" mkdir "problems/%problemname%"

:: make link to website
echo start https://open.kattis.com/problems/%problemname%> problems/%problemname%/kattis.bat

:: make base file
if not exist "problems/%problemname%/%problemname%.java" echo:> problems/%problemname%/%problemname%.java

:: make build file
echo javac %problemname%.java -encoding UTF-8> problems/%problemname%/build.bat
echo pause>> problems/%problemname%/build.bat

:: make run file
echo java %problemname%> problems/%problemname%/run.bat
echo pause>> problems/%problemname%/run.bat

:: make run with input file
echo java %problemname% ^< input.txt> problems/%problemname%/run-with-input.bat
echo pause>> problems/%problemname%/run-with-input.bat

:: make input file
if not exist "problems/%problemname%/input.txt" echo:> problems/%problemname%/input.txt

if [%1]==[] pause
