// Auto-generated structure: tagPROPVARIANT
// Source: tagPROPVARIANT.txt
// Fields count: 50
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct tagPROPVARIANT
{
    VARTYPE vt;
    PROPVAR_PAD1 wReserved1;
    PROPVAR_PAD2 wReserved2;
    PROPVAR_PAD3 wReserved3;
    CHAR cVal;
    UCHAR bVal;
    SHORT iVal;
    USHORT uiVal;
    LONG lVal;
    ULONG ulVal;
    INT intVal;
    UINT uintVal;
    LARGE_INTEGER hVal;
    ULARGE_INTEGER uhVal;
    FLOAT fltVal;
    DOUBLE dblVal;
    VARIANT_BOOL boolVal;
    SCODE scode;
    CY cyVal;
    DATE date;
    FILETIME filetime;
    BSTR bstrVal;
    BSTRBLOB bstrblobVal;
    BLOB blob;
    LPSTR pszVal;
    LPWSTR pwszVal;
    LPVERSIONEDSTREAM pVersionedStream;
    LPSAFEARRAY parray;
    CAC cac;
    CAUB caub;
    CAI cai;
    CAUI caui;
    CAL cal;
    CAUL caul;
    CAH cah;
    CAUH cauh;
    CAFLT caflt;
    CADBL cadbl;
    CABOOL cabool;
    CASCODE cascode;
    CACY cacy;
    CADATE cadate;
    CAFILETIME cafiletime;
    CACLSID cauuid;
    CACLIPDATA caclipdata;
    CABSTR cabstr;
    CABSTRBLOB cabstrblob;
    CALPSTR calpstr;
    CALPWSTR calpwstr;
    CAPROPVARIANT capropvar;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(tagPROPVARIANT) == EXPECTED_SIZE, "Size mismatch for tagPROPVARIANT");
