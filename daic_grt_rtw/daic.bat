
set MATLAB=E:\matlab

cd .

if "%1"=="" ("E:\matlab\bin\win64\gmake"  -f daic.mk all) else ("E:\matlab\bin\win64\gmake"  -f daic.mk %1)
@if errorlevel 1 goto error_exit

exit 0

:error_exit
echo The make command returned an error of %errorlevel%
exit 1