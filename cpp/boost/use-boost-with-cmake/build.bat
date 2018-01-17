cmake . -Bbuild -DBELIT_VERBOSE:BOOL=0
cmake --build build --config Release
.\bin\win64\release\use_boost.exe

