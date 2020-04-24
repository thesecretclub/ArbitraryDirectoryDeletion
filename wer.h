
typedef HANDLE HREPORT;

// Do not add heap dumps for reports for the process
#define WER_FAULT_REPORTING_FLAG_NOHEAP 1<<
// Queue critical reports for this process
#define WER_FAULT_REPORTING_FLAG_QUEUE 2
// Do not suspend the process before error reporting
#define WER_FAULT_REPORTING_FLAG_DISABLE_THREAD_SUSPENSION 4
// Queue critical reports for this process and upload from the queue
#define WER_FAULT_REPORTING_FLAG_QUEUE_UPLOAD 8
// Fault reporting UI should always be shown. This is only applicable for interactive processes
#define WER_FAULT_REPORTING_ALWAYS_SHOW_UI 16
// Fault reporting UI should not be shown.
#define WER_FAULT_REPORTING_NO_UI 32
// Do not add heap dumps when queueing reports for the process
#define WER_FAULT_REPORTING_FLAG_NO_HEAP_ON_QUEUE 64
// Disable snapshots for crash/exception reporting.
#define WER_FAULT_REPORTING_DISABLE_SNAPSHOT_CRASH 128
// Disable snapshots for hang reporting.
#define WER_FAULT_REPORTING_DISABLE_SNAPSHOT_HANG 256
// Mark the process as critical.
#define WER_FAULT_REPORTING_CRITICAL 512
// Mark the process as requiring flushing of its report store.
#define WER_FAULT_REPORTING_DURABLE 1024

// This is the maximum length of any created URL
// NOTE: This constant is obsolete since Win9.
#define WER_MAX_TOTAL_PARAM_LENGTH 1720

// Number of extra modules that we can select to get extra data in the minidump
#define WER_MAX_PREFERRED_MODULES 128
#define WER_MAX_PREFERRED_MODULES_BUFFER 256

// The maximum size of memory block that can be registered
#define WER_MAX_MEM_BLOCK_SIZE ( 64 * 1024 )

// Event Type constants for application crashes
#define APPCRASH_EVENT L"APPCRASH"
#define PACKAGED_APPCRASH_EVENT L"MoAppCrash"

// Indexes for the parameter ids
#define WER_P0 0
#define WER_P1 1
#define WER_P2 2
#define WER_P3 3
#define WER_P4 4
#define WER_P5 5
#define WER_P6 6
#define WER_P7 7
#define WER_P8 8
#define WER_P9 9

// Custom error HRESULTS
#define WER_E_INSUFFICIENT_BUFFER ( HRESULT_FROM_WIN32( ERROR_INSUFFICIENT_BUFFER ) )
#define WER_E_NOT_FOUND ( HRESULT_FROM_WIN32( ERROR_NOT_FOUND ) )
#define WER_E_LENGTH_EXCEEDED ( HRESULT_FROM_WIN32( ERROR_PARAMETER_QUOTA_EXCEEDED ) )
#define WER_E_INVALID_STATE ( HRESULT_FROM_WIN32( ERROR_INVALID_STATE ) )
#define WER_E_MISSING_DUMP ( HRESULT_FROM_WIN32( ERROR_MISSING_SYSTEMFILE ) )
#define WER_E_CABBING_FAILURE ( HRESULT_FROM_WIN32( ERROR_GEN_FAILURE ) )

/////////////////////////////////////////////////////////////////////////////
// The enum that describes the indexes of the customizable UI strings
typedef enum _WER_REPORT_UI
{
   WerUIAdditionalDataDlgHeader = 1,
   WerUIIconFilePath = 2,
   WerUIConsentDlgHeader = 3,
   WerUIConsentDlgBody = 4,
   WerUIOnlineSolutionCheckText = 5,
   WerUIOfflineSolutionCheckText = 6,
   WerUICloseText = 7,
   WerUICloseDlgHeader = 8,
   WerUICloseDlgBody = 9,
   WerUICloseDlgButtonText = 10,
   WerUIMax
} WER_REPORT_UI;

// The type of the registered files
typedef enum _WER_REGISTER_FILE_TYPE
{
   WerRegFileTypeUserDocument = 1,
   WerRegFileTypeOther = 2,
   WerRegFileTypeMax
} WER_REGISTER_FILE_TYPE;

// The type of files that can be added to the report
typedef enum _WER_FILE_TYPE
{
   WerFileTypeMicrodump = 1,
   WerFileTypeMinidump = 2,
   WerFileTypeHeapdump = 3,
   WerFileTypeUserDocument = 4,
   WerFileTypeOther = 5,
   WerFileTypeTriagedump = 6,
   WerFileTypeCustomDump = 7,
   WerFileTypeAuxiliaryDump = 8,
   WerFileTypeEtlTrace = 9,
   WerFileTypeMax
} WER_FILE_TYPE;

typedef enum _WER_SUBMIT_RESULT
{
   WerReportQueued = 1,
   WerReportUploaded = 2,
   WerReportDebug = 3,
   WerReportFailed = 4,
   WerDisabled = 5,
   WerReportCancelled = 6,
   WerDisabledQueue = 7,
   WerReportAsync = 8,
   WerCustomAction = 9,

   WerThrottled = 10,
   WerReportUploadedCab = 11,
   WerStorageLocationNotFound = 12,

   WerSubmitResultMax
} WER_SUBMIT_RESULT,

* PWER_SUBMIT_RESULT;

// The type of the report
typedef enum _WER_REPORT_TYPE
{
   WerReportNonCritical = 0,
   WerReportCritical = 1,
   WerReportApplicationCrash = 2,
   WerReportApplicationHang = 3,
   WerReportKernel = 4,
   WerReportInvalid
} WER_REPORT_TYPE;


// Flags that can be specified when adding a file to the report.
// NOTE: These should always occupy the lower 16 bits of the file flag dword.
// The upper 16 bits are reserved for internal use and get cleared by WerAddFile.
#define WER_FILE_DELETE_WHEN_DONE 1 // Delete the file once WER is done
#define WER_FILE_ANONYMOUS_DATA 2   // This file does not contain any PII
#define WER_FILE_COMPRESSED 4       // This file has been compressed using SQS

// Report submission flags.
#define WER_SUBMIT_HONOR_RECOVERY 1                     // show recovery option
#define WER_SUBMIT_HONOR_RESTART 2                      // show application restart option
#define WER_SUBMIT_QUEUE 4                              // report directly to queue
#define WER_SUBMIT_SHOW_DEBUG 8                         // show the debug button
#define WER_SUBMIT_ADD_REGISTERED_DATA 16               // Add registered data to the WER report
#define WER_SUBMIT_OUTOFPROCESS 32                      // Force the report to go out of process
#define WER_SUBMIT_NO_CLOSE_UI 64                       // Do not show the close dialog for the critical report
#define WER_SUBMIT_NO_QUEUE 128                         // Do not queue the report
#define WER_SUBMIT_NO_ARCHIVE 256                       // Do not archive the report
#define WER_SUBMIT_START_MINIMIZED 512                  // The initial reporting UI is minimized and will flash
#define WER_SUBMIT_OUTOFPROCESS_ASYNC 1024              // Force the report to go out of process and do not wait for it to finish
#define WER_SUBMIT_BYPASS_DATA_THROTTLING 2048          // Bypass data throttling for the report
#define WER_SUBMIT_ARCHIVE_PARAMETERS_ONLY 4096         // Archive only the parameters; the cab is discarded
#define WER_SUBMIT_REPORT_MACHINE_ID 8192               // Always send the machine ID, regardless of the consent the report was submitted with
#define WER_SUBMIT_BYPASS_POWER_THROTTLING 16384        // Bypass power-related throttling (when on battery)
#define WER_SUBMIT_BYPASS_NETWORK_COST_THROTTLING 32768 // Bypass network-related throttling (when on restricted networks)

#define WER_SUBMIT_DISCARD_IF_QUEUED WER_SUBMIT_NO_QUEUE

#if( NTDDI_VERSION >= NTDDI_WIN8 )
typedef struct _WER_REPORT_INFORMATION_V3 {
   DWORD  dwSize;
   HANDLE hProcess;
   WCHAR  wzConsentKey[64];
   WCHAR  wzFriendlyEventName[128];
   WCHAR  wzApplicationName[128];
   WCHAR  wzApplicationPath[MAX_PATH];
   WCHAR  wzDescription[512];
   HWND   hwndParent;
   WCHAR  wzNamespacePartner[64];
   WCHAR  wzNamespaceGroup[64];
} WER_REPORT_INFORMATION_V3, * PWER_REPORT_INFORMATION_V3;
#endif // NTDDI_VERSION >= NTDDI_WIN8

typedef struct _WER_DUMP_CUSTOM_OPTIONS {
   DWORD dwSize;
   DWORD dwMask;
   DWORD dwDumpFlags;
   BOOL  bOnlyThisThread;
   DWORD dwExceptionThreadFlags;
   DWORD dwOtherThreadFlags;
   DWORD dwExceptionThreadExFlags;
   DWORD dwOtherThreadExFlags;
   DWORD dwPreferredModuleFlags;
   DWORD dwOtherModuleFlags;
   WCHAR wzPreferredModuleList[WER_MAX_PREFERRED_MODULES_BUFFER];

} WER_DUMP_CUSTOM_OPTIONS, * PWER_DUMP_CUSTOM_OPTIONS;

typedef struct _WER_DUMP_CUSTOM_OPTIONS_V2 {
   DWORD dwSize;
   DWORD dwMask;
   DWORD dwDumpFlags;
   BOOL  bOnlyThisThread;
   DWORD dwExceptionThreadFlags;
   DWORD dwOtherThreadFlags;
   DWORD dwExceptionThreadExFlags;
   DWORD dwOtherThreadExFlags;
   DWORD dwPreferredModuleFlags;
   DWORD dwOtherModuleFlags;
   WCHAR wzPreferredModuleList[WER_MAX_PREFERRED_MODULES_BUFFER];
   DWORD dwPreferredModuleResetFlags;
   DWORD dwOtherModuleResetFlags;
} WER_DUMP_CUSTOM_OPTIONS_V2, * PWER_DUMP_CUSTOM_OPTIONS_V2;

#if( NTDDI_VERSION >= NTDDI_WINBLUE )
typedef struct _WER_REPORT_INFORMATION_V4 {
   DWORD  dwSize;
   HANDLE hProcess;
   WCHAR  wzConsentKey[64];
   WCHAR  wzFriendlyEventName[128];
   WCHAR  wzApplicationName[128];
   WCHAR  wzApplicationPath[MAX_PATH];
   WCHAR  wzDescription[512];
   HWND   hwndParent;
   WCHAR  wzNamespacePartner[64];
   WCHAR  wzNamespaceGroup[64];
   BYTE   rgbApplicationIdentity[16];
   HANDLE hSnapshot;
   HANDLE hDeleteFilesImpersonationToken;
} WER_REPORT_INFORMATION_V4, * PWER_REPORT_INFORMATION_V4;
typedef WER_REPORT_INFORMATION_V4 const* PCWER_REPORT_INFORMATION_V4;
#endif // NTDDI_VERSION >= NTDDI_WINBLUE

#if( NTDDI_VERSION >= NTDDI_WIN10 )
typedef struct _WER_REPORT_INFORMATION {
   DWORD             dwSize;
   HANDLE            hProcess;
   WCHAR             wzConsentKey[64];
   WCHAR             wzFriendlyEventName[128];
   WCHAR             wzApplicationName[128];
   WCHAR             wzApplicationPath[MAX_PATH];
   WCHAR             wzDescription[512];
   HWND              hwndParent;
   WCHAR             wzNamespacePartner[64];
   WCHAR             wzNamespaceGroup[64];
   BYTE              rgbApplicationIdentity[16];
   HANDLE            hSnapshot;
   HANDLE            hDeleteFilesImpersonationToken;
   WER_SUBMIT_RESULT submitResultMax;
} WER_REPORT_INFORMATION, * PWER_REPORT_INFORMATION;
typedef WER_REPORT_INFORMATION const* PCWER_REPORT_INFORMATION;
#endif // NTDDI_VERSION >= NTDDI_WIN10


typedef struct _WER_DUMP_CUSTOM_OPTIONS_V3 {
   DWORD dwSize;
   DWORD dwMask;
   DWORD dwDumpFlags;
   BOOL  bOnlyThisThread;
   DWORD dwExceptionThreadFlags;
   DWORD dwOtherThreadFlags;
   DWORD dwExceptionThreadExFlags;
   DWORD dwOtherThreadExFlags;
   DWORD dwPreferredModuleFlags;
   DWORD dwOtherModuleFlags;
   WCHAR wzPreferredModuleList[WER_MAX_PREFERRED_MODULES_BUFFER];
   DWORD dwPreferredModuleResetFlags;
   DWORD dwOtherModuleResetFlags;

   PVOID  pvDumpKey;
   HANDLE hSnapshot;
   DWORD  dwThreadID;
} WER_DUMP_CUSTOM_OPTIONS_V3, * PWER_DUMP_CUSTOM_OPTIONS_V3;
typedef WER_DUMP_CUSTOM_OPTIONS_V3 const* PCWER_DUMP_CUSTOM_OPTIONS_V3;

typedef struct _WER_EXCEPTION_INFORMATION {
   PEXCEPTION_POINTERS pExceptionPointers;
   BOOL                bClientPointers;
} WER_EXCEPTION_INFORMATION, * PWER_EXCEPTION_INFORMATION;

typedef enum _WER_CONSENT
{
   WerConsentNotAsked = 1,
   WerConsentApproved = 2,
   WerConsentDenied = 3,
   WerConsentAlwaysPrompt = 4,
   WerConsentMax
} WER_CONSENT;

template< typename modHandleType, typename procNameType >
auto getProcAddressOrThrow(modHandleType modHandle, procNameType procName) {
   auto address = GetProcAddress(modHandle, procName);
   if (address == nullptr) throw std::exception{ (std::string{"Error importing: "} +(std::string{procName})).c_str() };
   return address;
}

#define CONCAT( id1, id2 ) id1##id2
// Notice- the comma operator is used to make sure the dll is loaded, discard the result- then getModuleHandle is used

#define IMPORTAPI( DLLFILE, FUNCNAME, RETTYPE, ... )                                                                        \
   typedef RETTYPE( WINAPI* CONCAT( t_, FUNCNAME ) )( __VA_ARGS__ );                                                        \
   template< typename... Ts >                                                                                               \
   auto FUNCNAME( Ts... ts ) {                                                                                              \
      const static CONCAT( t_, FUNCNAME ) func =                                                                            \
       (CONCAT( t_, FUNCNAME )) getProcAddressOrThrow( ( LoadLibrary( DLLFILE ), GetModuleHandle( DLLFILE ) ), #FUNCNAME ); \
      return func( std::forward< Ts >( ts )... );                                                                           \
   } 


IMPORTAPI(L"WER.dll", WerSysprepCleanup, HRESULT, __int64 number);
IMPORTAPI(L"WER.dll", WerpAddAppCompatData, void, int* param_1, LPCWSTR param_2, wchar_t* param_3);
IMPORTAPI(L"WER.dll", WerpReportCancel, HRESULT, HREPORT hReportHandle);
IMPORTAPI(L"WER.dll", WerReportSetParameter, HRESULT, HREPORT, DWORD dwparamID, PCWSTR pwzName, PCWSTR pwzValue);
IMPORTAPI(L"WER.dll", WerReportAddFile, HRESULT, HREPORT, PCWSTR pwzPath, WER_FILE_TYPE, DWORD dwFileFlags);
IMPORTAPI(L"WER.dll", WerReportCloseHandle, HRESULT, HREPORT hReportHandle);
IMPORTAPI(L"WER.dll", WerReportSubmit, HRESULT, HREPORT, WER_CONSENT consent, DWORD dwFlags, PWER_SUBMIT_RESULT);
IMPORTAPI(L"WER.dll", WerpCreateMachineStore, HRESULT);
IMPORTAPI(L"WER.dll", WerRegisterAppLocalDump, HRESULT, PCWSTR localAppDataRelativePath);
IMPORTAPI(L"WER.dll", WerpCleanWer, HRESULT, HREPORT);
IMPORTAPI(L"WER.dll", WerReportCreate, HRESULT, PCWSTR pwzEventType, WER_REPORT_TYPE repType, PWER_REPORT_INFORMATION pReportInformation, HREPORT* phReportHandle);
IMPORTAPI(L"kernel32.dll", WerRegisterRuntimeExceptionModule, HRESULT, PCWSTR dll, PVOID);

#define safecpy( src, dest ) lstrcpynW( dest, src, ARRAYSIZE( src ) )

bool submitBlankReport(bool async = false) 
{
   WER_REPORT_INFORMATION report = { 0 };  
   report.dwSize = sizeof(WER_REPORT_INFORMATION);
   if (!safecpy(L".", report.wzConsentKey)) throw  std::exception{ "Failed to set consent key" };
   if (!safecpy(L"  ", report.wzApplicationName)) throw  std::exception{ "Fai  led to set app name" };
   if (!safecpy(L"WER", report.wzApplicationPath)) throw  std::exception{ "Failed to set AppPath" };
   if (!safecpy(L"", report.wzDescription)) throw  std::exception{ "Failed to set description" };
   if (!safecpy(L"", report.wzFriendlyEventName)) throw  std::exception{ "Failed to set FriendlyEventName" };

   auto reportCloser = [](HREPORT* report) {
      if (FAILED(WerReportCloseHandle(*report))) throw  std::exception{ "ReportCancel failed" };
      delete report;
   };
   auto hReport{ std::unique_ptr< HREPORT, decltype(reportCloser) > { new HREPORT {}, reportCloser } };

   if( FAILED(WerReportCreate(L".", WerReportNonCritical, &report, hReport.get())) )
      throw  std::exception{ "WerReportCreate failed" };

   WER_SUBMIT_RESULT SubmitResult;
   if( FAILED(
      WerReportSubmit(
         *hReport.get(),
         WerConsentNotAsked,
         (async ? WER_SUBMIT_OUTOFPROCESS_ASYNC : WER_SUBMIT_OUTOFPROCESS) | WER_SUBMIT_QUEUE | WER_SUBMIT_ARCHIVE_PARAMETERS_ONLY,
         &SubmitResult  
      )
   ))  { throw std::exception{ "WerReportSubmit failed, error" }; }
      
   std::wcout << L"Submission result was:"s << SubmitResult << std::endl;

   return true;
}
