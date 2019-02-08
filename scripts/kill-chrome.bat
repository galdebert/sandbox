@echo off 
 
for /f "tokens=1 delims=" %%# in ('qprocess^|find /i /c /n "chrome"') do ( 
    set count=%%# 
) 
 
taskkill /F /IM chrome.exe /T 
 
echo Number of Google Chrome processes removed: %count% 
pause
