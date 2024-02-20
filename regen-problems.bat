@echo off

:: Regenerate the files not tracked by Git
for /D %%s in (problems/*) do (
	if exist "problems/%%s/main.cpp" (
		:: C++ solution
		call new-problem.bat %%s
	) else (
		if exist "problems/%%s/%%s.java" (
			:: Java solution
			call new-problem-java.bat %%s
		)
	)
)

pause