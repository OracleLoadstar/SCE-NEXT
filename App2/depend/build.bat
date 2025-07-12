call "E:\vs\IDE\Common7\Tools\VsMSBuildCmd.bat"
mkdir bin
msbuild /p:OutputPath=.\bin\ /p:AssemblyName=SupportCardEvaluator
if %errorlevel% NEQ 0 (
    exit /b 1
)
robocopy /mir .\x64\Debug\ .\bin\
rem //powershell --command "./bin/SupportCardEvaluator.exe"