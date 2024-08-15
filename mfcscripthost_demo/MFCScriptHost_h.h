

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


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


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __MFCScriptHost_h_h__
#define __MFCScriptHost_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IHost_Proxy_FWD_DEFINED__
#define __IHost_Proxy_FWD_DEFINED__
typedef interface IHost_Proxy IHost_Proxy;
#endif 	/* __IHost_Proxy_FWD_DEFINED__ */


#ifndef __IHostEvent_FWD_DEFINED__
#define __IHostEvent_FWD_DEFINED__
typedef interface IHostEvent IHostEvent;
#endif 	/* __IHostEvent_FWD_DEFINED__ */


#ifndef __Host_Proxy_FWD_DEFINED__
#define __Host_Proxy_FWD_DEFINED__

#ifdef __cplusplus
typedef class Host_Proxy Host_Proxy;
#else
typedef struct Host_Proxy Host_Proxy;
#endif /* __cplusplus */

#endif 	/* __Host_Proxy_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __MFCScriptHost_LIBRARY_DEFINED__
#define __MFCScriptHost_LIBRARY_DEFINED__

/* library MFCScriptHost */
/* [version][uuid] */ 


DEFINE_GUID(LIBID_MFCScriptHost,0xE662E9C0,0x01DB,0x4A0C,0x9A,0xF9,0x06,0xF8,0xFF,0xB7,0xAC,0xBE);

#ifndef __IHost_Proxy_DISPINTERFACE_DEFINED__
#define __IHost_Proxy_DISPINTERFACE_DEFINED__

/* dispinterface IHost_Proxy */
/* [uuid] */ 


DEFINE_GUID(DIID_IHost_Proxy,0xBC810D88,0x1564,0x46CF,0x96,0x0A,0x6B,0xD3,0x65,0x3E,0x91,0xD7);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("BC810D88-1564-46CF-960A-6BD3653E91D7")
    IHost_Proxy : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IHost_ProxyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHost_Proxy * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHost_Proxy * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHost_Proxy * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IHost_Proxy * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IHost_Proxy * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IHost_Proxy * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IHost_Proxy * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IHost_ProxyVtbl;

    interface IHost_Proxy
    {
        CONST_VTBL struct IHost_ProxyVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHost_Proxy_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IHost_Proxy_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IHost_Proxy_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IHost_Proxy_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IHost_Proxy_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IHost_Proxy_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IHost_Proxy_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IHost_Proxy_DISPINTERFACE_DEFINED__ */


#ifndef __IHostEvent_DISPINTERFACE_DEFINED__
#define __IHostEvent_DISPINTERFACE_DEFINED__

/* dispinterface IHostEvent */
/* [uuid] */ 


DEFINE_GUID(DIID_IHostEvent,0x740C1C2D,0x692F,0x43F8,0x85,0xFF,0x38,0xDE,0xE1,0x74,0x28,0x19);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("740C1C2D-692F-43F8-85FF-38DEE1742819")
    IHostEvent : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IHostEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHostEvent * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHostEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHostEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IHostEvent * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IHostEvent * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IHostEvent * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IHostEvent * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IHostEventVtbl;

    interface IHostEvent
    {
        CONST_VTBL struct IHostEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHostEvent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IHostEvent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IHostEvent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IHostEvent_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IHostEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IHostEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IHostEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IHostEvent_DISPINTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_Host_Proxy,0xF8235A29,0xC576,0x439D,0xA0,0x70,0x6E,0x79,0x80,0xC9,0xC3,0xF6);

#ifdef __cplusplus

class DECLSPEC_UUID("F8235A29-C576-439D-A070-6E7980C9C3F6")
Host_Proxy;
#endif
#endif /* __MFCScriptHost_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


