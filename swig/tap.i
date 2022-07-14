%module(directors="1") tap
%include "typemaps.i"
%insert(cgo_comment)
%{
#cgo CFLAGS:-fvisibility=hidden -O2
#cgo amd64 CFLAGS: -m64
#cgo amd64 LDFLAGS: -L${SRCDIR}/swig
#cgo CFLAGS: -I${SRCDIR}/swig
#cgo LDFLAGS: -static -ltapwrapgo -lTapQuoteAPI -liconv -lstdc++
%}

%{
#include "TapAPICommDef.h"
#include "TapAPIError.h"
#include "TapQuoteAPI.h"
#include "TapQuoteAPIDataType.h"
%}
%apply int &OUTPUT { TAPIINT32 &iResult };
%feature("director") ITapQuoteAPINotify;
%include "TapAPICommDef.h"
%include "TapAPIError.h"
%include "TapQuoteAPI.h"
%include "TapQuoteAPIDataType.h"