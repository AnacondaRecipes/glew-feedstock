setlocal EnableDelayedExpansion

cd build
:: Configure using the CMakeFiles
cmake -G "Ninja" ^
    -DCMAKE_BUILD_TYPE=Release ^
    -DCMAKE_INSTALL_PREFIX="%LIBRARY_PREFIX%" ^
    -DCMAKE_INSTALL_LIBDIR="lib" ^
    -DCMAKE_PREFIX_PATH="%LIBRARY_PREFIX%" ^
    ./cmake

if errorlevel 1 exit 1

:: Build!
cmake --build . --target install
if errorlevel 1 exit 1

