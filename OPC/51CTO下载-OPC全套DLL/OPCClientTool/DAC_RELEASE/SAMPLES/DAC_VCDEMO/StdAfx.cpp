// stdafx.cpp : source file that includes just the standard includes
//	DAC_VCDEMO.pch will be the pre-compiled header
//	stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"
#include "TIME.H"

HMODULE hLibrary;
DWORD ServerHandle, GroupHandle;
CString ServerName, ServerClassID, ComputerName,GroupName,ItemName, ItemWriteValue;
BOOL Active, ASync;
DWORD Version, UpdateRate;
int TimeBias;
float DeadBand;


CString VariantToString(VARIANT v)
{
	CString strText;
	switch(v.vt)
	{
	case VT_I2:
		strText.Format(TEXT("%d"),v.intVal);
		break;
	case VT_I4:
		strText.Format(TEXT("%d"),v.intVal);
		break;
	case VT_BSTR:
		strText.Format(TEXT("%d"),v.boolVal);
		break;
	case VT_R4:
		strText.Format(TEXT("%f"),v.dblVal);
		break;
	case VT_R8:
		strText.Format(TEXT("%f"),v.dblVal);
		break;
	case VT_BOOL:
		if(v.boolVal)
			strText="TRUE";
		else
			strText="FALSE";
		break;
	case VT_DATE:
		COleDateTime dt(v);
		_SYSTEMTIME st;
		_FILETIME ft;
		dt.GetAsSystemTime(st);
		SystemTimeToFileTime(&st, &ft);
		strText=FileTimeToString(ft);
		break;
	};

	return strText;
}

CString FileTimeToString(_FILETIME ft)
{
	_SYSTEMTIME st;
	_FILETIME ft1;
	FileTimeToLocalFileTime(&ft, &ft1);
	CString strText;
	FileTimeToSystemTime(&ft1, &st);
	strText.Format(TEXT("%d-%d-%d %d:%d:%d"),st.wYear,st.wMonth,st.wDay,st.wHour,st.wMinute,st.wSecond);
	return strText;
}

CString IntToString(int i)
{
	CString strText;
	strText.Format(TEXT("%d"),i);
	return strText;
}
