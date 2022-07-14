cd /d %~dp0

cl /O2 -I. /DTAP_VERSION=9.3.1.4 /DISLIB /DWIN32 /DLIB_TAP_API_EXPORT /LD /MT /Fe..\..\wrap\wrap.dll ..\..\wrap\wrap.cpp TapQuoteAPI.lib

swig -c++ -go -intgosize 64 ..\..\swig\tap.i
g++ -o..\..\swig\tapwrapgo.o -c -m64 -I. -I..\..\swig ..\..\swig\tap_wrap.cxx
ar -crv ..\..\swig\libtapwrapgo.a ..\..\swig\tapwrapgo.o
del ..\..\swig\tapwrapgo.o
move ..\..\swig\tap.go ..\..\tap_windows.go
copy TapQuoteAPI.lib ..\..\wrap\TapQuoteAPI.lib
cd ..\..
go install -x