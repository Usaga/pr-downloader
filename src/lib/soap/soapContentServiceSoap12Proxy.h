/* soapContentServiceSoap12Proxy.h
   Generated by gSOAP 2.8.3 from plasma.h

Copyright(C) 2000-2011, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
1) GPL or 2) Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#ifndef soapContentServiceSoap12Proxy_H
#define soapContentServiceSoap12Proxy_H
#include "soapH.h"

class SOAP_CMAC ContentServiceSoap12Proxy : public soap
{ public:
	/// Endpoint URL of service 'ContentServiceSoap12Proxy' (change as needed)
	const char *soap_endpoint;
	/// Constructor
	ContentServiceSoap12Proxy();
	/// Constructor with copy of another engine state
	ContentServiceSoap12Proxy(const struct soap&);
	/// Constructor with endpoint URL
	ContentServiceSoap12Proxy(const char *url);
	/// Constructor with engine input+output mode control
	ContentServiceSoap12Proxy(soap_mode iomode);
	/// Constructor with URL and input+output mode control
	ContentServiceSoap12Proxy(const char *url, soap_mode iomode);
	/// Constructor with engine input and output mode control
	ContentServiceSoap12Proxy(soap_mode imode, soap_mode omode);
	/// Destructor frees deserialized data
	virtual	~ContentServiceSoap12Proxy();
	/// Initializer used by constructors
	virtual	void ContentServiceSoap12Proxy_init(soap_mode imode, soap_mode omode);
	/// Delete all deserialized data (uses soap_destroy and soap_end)
	virtual	void destroy();
	/// Disables and removes SOAP Header from message
	virtual	void soap_noheader();
	/// Get SOAP Header structure (NULL when absent)
	virtual	const SOAP_ENV__Header *soap_header();
	/// Get SOAP Fault structure (NULL when absent)
	virtual	const SOAP_ENV__Fault *soap_fault();
	/// Get SOAP Fault string (NULL when absent)
	virtual	const char *soap_fault_string();
	/// Get SOAP Fault detail as string (NULL when absent)
	virtual	const char *soap_fault_detail();
	/// Force close connection (normally automatic, except for send_X ops)
	virtual	int soap_close_socket();
	/// Print fault
	virtual	void soap_print_fault(FILE*);
#ifndef WITH_LEAN
	/// Print fault to stream
	virtual	void soap_stream_fault(std::ostream&);
	/// Put fault into buffer
	virtual	char *soap_sprint_fault(char *buf, size_t len);
#endif

	/// Web service operation 'DownloadFile' (returns error code or SOAP_OK)
	virtual	int DownloadFile(_Plasma__DownloadFile *Plasma__DownloadFile, _Plasma__DownloadFileResponse *Plasma__DownloadFileResponse) { return DownloadFile(NULL, NULL, Plasma__DownloadFile, Plasma__DownloadFileResponse); }
	virtual	int DownloadFile(const char *endpoint, const char *soap_action, _Plasma__DownloadFile *Plasma__DownloadFile, _Plasma__DownloadFileResponse *Plasma__DownloadFileResponse);
};
#endif
