REM g++ -o demo demo.c -I. -L. -lDVP_CAMSDK
rem g++ -c -DBUILD_DLL demo.c
g++ -shared -o dvpcam.dll demo.c DVP_CAMSDK.dll
copy dvpcam.dll GUI