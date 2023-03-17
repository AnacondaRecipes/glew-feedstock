:: conda env create -f %RECIPE_DIR%\test\test-environment-windows.yml
:: activate test-environment-windows
md build
cd build
cmake  -G "NMake Makefiles" %RECIPE_DIR%/test -DCMAKE_BUILD_TYPE=Release
nmake
echo try to execute main application
.\main  || cmd /k "exit /b 0"

dir %PREFIX%\Library\bin
dir $PREFIX%\bin

visualinfo.exe || cmd /k "exit /b 0"
glewinfo.exe || cmd /k "exit /b 0"

