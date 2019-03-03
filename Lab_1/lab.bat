@echo off
chcp 1251 >nul
cd /d d:/lab
mkdir fold1
cd d:/lab/fold1
mkdir fold2 
cd d:/lab/fold1/fold2
mkdir fold3 
cd d:/lab/fold1
echo %date%>>date1.txt
copy d:\lab\fold1\date1.txt d:\lab\fold1\fold2\date1.txt
cd d:/lab/fold1/fold2
rename "d:\lab\fold1\fold2\date1.txt" date2.txt
for %%i in (date2.txt) do set a=%%~ni
echo %a% >> count.txt
for %%i in (count.txt) do set /a b=%%~zi-3
echo %b% >> date2.txt
del count.txt
copy d:\lab\fold1\fold2\date2.txt d:\lab\fold1\fold2\fold3\date2.txt
cd d:\lab\fold1\fold2\fold3
systeminfo >> date2.txt