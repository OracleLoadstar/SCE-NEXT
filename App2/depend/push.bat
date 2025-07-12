@echo off
rd /s /q .vs
rd /s /q bin
rd /s /q Uma_SCE_Test
rd /s /q x64
del /s /q Assets\Data\User\*
del /s /q Assets\Data\Save\*
::rd /s /q Assets
:pull
git pull -v
if %ERRORLEVEL% neq 0 (
	goto pull

)
ping 127.0.0.1 /n 3 >nul
cls
echo ===================
echo 上一次tag: & powershell cat ./version.txt
echo ===================
set /p name="tag name:"
echo %name% > .\version.txt
set /p commit="commit:"
set /p closeing="上传后自动关机(y/r/n)"

git add . -v
git commit -v -m "%commit%"
:push
git push -v
if %ERRORLEVEL% neq 0 (
	goto push
)
del /s /q ../SCE_laster.7z
7z a -t7z -m0=lzma2 -mx9 -mfb=64 -md=32m -ms=on ../SCE_laster.7z .



git tag -a "%name%" -m "%commit%"
:tag
git push --tags -v
if %ERRORLEVEL% neq 0 (
	goto tag
)
if "%closeing%" == "y" (
	shutdown /s /t 10
)
if "%closeing%" == "r" (
	shutdown /r /t 10
)
