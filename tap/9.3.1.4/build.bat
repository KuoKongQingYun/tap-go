cd /d %~dp0

swig -c++ -go -intgosize 64 ..\..\swig\tap.i
g++ -o..\..\swig\tapwrapgo.o -c -m64 -I. -I..\..\swig ..\..\swig\tap_wrap.cxx
ar -crv ..\..\swig\libtapwrapgo.a ..\..\swig\tapwrapgo.o
del ..\..\swig\tapwrapgo.o
move ..\..\swig\tap.go ..\..\tap_windows.go
copy TapQuoteAPI.lib ..\..\swig\TapQuoteAPI.lib
cd ..\..
go install -x