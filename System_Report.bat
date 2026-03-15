@echo off
setlocal

:: Название папки и имя файла
set "FolderName=user_settings_files"
set "FileName=System_Report.txt"

:: Создаем папку в текущей директории, если её еще нет
if not exist "%~dp0%FolderName%" mkdir "%~dp0%FolderName%"

:: Полный путь к итоговому файлу
set "FullPath=%~dp0%FolderName%\%FileName%"

echo Collecting system data, please wait...

echo ========================================== > "%FullPath%"
echo      FULL SYSTEM INFORMATION REPORT        >> "%FullPath%"
echo      Generated: %date% %time%              >> "%FullPath%"
echo ========================================== >> "%FullPath%"
echo. >> "%FullPath%"

echo [1. OPERATING SYSTEM] >> "%FullPath%"
wmic os get Caption, Version, OSArchitecture /value | findstr /v "^$" >> "%FullPath%"
echo. >> "%FullPath%"

echo [2. PROCESSOR] >> "%FullPath%"
wmic cpu get Name, NumberOfCores, MaxClockSpeed /value | findstr /v "^$" >> "%FullPath%"
echo. >> "%FullPath%"

echo [3. RAM] >> "%FullPath%"
wmic ComputerSystem get TotalPhysicalMemory /value | findstr /v "^$" >> "%FullPath%"
wmic memorychip get Capacity, Speed /value | findstr /v "^$" >> "%FullPath%"
echo. >> "%FullPath%"

echo [4. GRAPHICS CARD] >> "%FullPath%"
wmic path win32_VideoController get Name, DriverVersion /value | findstr /v "^$" >> "%FullPath%"
echo. >> "%FullPath%"

echo [5. NETWORK (IP AND MAC)] >> "%FullPath%"
ipconfig /all | findstr /C:"Description" /C:"Physical Address" /C:"IPv4 Address" >> "%FullPath%"
echo. >> "%FullPath%"

echo [6. BIOS AND SERIAL NUMBER] >> "%FullPath%"
wmic bios get SMBIOSBIOSVersion, SerialNumber /value | findstr /v "^$" >> "%FullPath%"

echo ==========================================
echo Done! Report saved in: %FolderName%\%FileName%
echo Full Path: %FullPath%
pause
