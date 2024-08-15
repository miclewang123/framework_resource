

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Fri Oct 10 14:36:20 2014
 */
/* Compiler settings for .\MFCScriptHost.odl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, LIBID_MFCScriptHost,0xE662E9C0,0x01DB,0x4A0C,0x9A,0xF9,0x06,0xF8,0xFF,0xB7,0xAC,0xBE);


MIDL_DEFINE_GUID(IID, DIID_IHost_Proxy,0xBC810D88,0x1564,0x46CF,0x96,0x0A,0x6B,0xD3,0x65,0x3E,0x91,0xD7);


MIDL_DEFINE_GUID(IID, DIID_IHostEvent,0x740C1C2D,0x692F,0x43F8,0x85,0xFF,0x38,0xDE,0xE1,0x74,0x28,0x19);


MIDL_DEFINE_GUID(CLSID, CLSID_Host_Proxy,0xF8235A29,0xC576,0x439D,0xA0,0x70,0x6E,0x79,0x80,0xC9,0xC3,0xF6);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



