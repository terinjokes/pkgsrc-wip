$NetBSD$

--- chrome/app/chrome_main_delegate.cc.orig	2016-06-24 01:02:10.000000000 +0000
+++ chrome/app/chrome_main_delegate.cc
@@ -111,7 +111,7 @@
 #include "ui/base/x/x11_util.h"
 #endif
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 #include "components/crash/content/app/breakpad_linux.h"
 #endif
 
@@ -543,7 +543,7 @@ bool ChromeMainDelegate::BasicStartupCom
       std::string format_str =
           command_line.GetSwitchValueASCII(switches::kDiagnosticsFormat);
       if (format_str == "machine") {
-        format = diagnostics::DiagnosticsWriter::MACHINE;
+        format = diagnostics::DiagnosticsWriter::THEMACHINE;
       } else if (format_str == "log") {
         format = diagnostics::DiagnosticsWriter::LOG;
       } else {
@@ -593,7 +593,7 @@ bool ChromeMainDelegate::BasicStartupCom
       std::string format_str =
           command_line.GetSwitchValueASCII(switches::kDiagnosticsFormat);
       if (format_str == "machine") {
-        format = diagnostics::DiagnosticsWriter::MACHINE;
+        format = diagnostics::DiagnosticsWriter::THEMACHINE;
       } else if (format_str == "human") {
         format = diagnostics::DiagnosticsWriter::HUMAN;
       } else {
@@ -684,7 +684,7 @@ void ChromeMainDelegate::PreSandboxStart
   std::string process_type =
       command_line.GetSwitchValueASCII(switches::kProcessType);
 
-#if defined(OS_POSIX)
+#if defined(OS_POSIX) && !defined(OS_BSD)
   crash_reporter::SetCrashReporterClient(g_chrome_crash_client.Pointer());
 #endif
 
@@ -805,7 +805,7 @@ void ChromeMainDelegate::PreSandboxStart
   chrome::InitializePDF();
 #endif
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
   // Zygote needs to call InitCrashReporter() in RunZygote().
   if (process_type != switches::kZygoteProcess) {
 #if defined(OS_ANDROID)
@@ -823,7 +823,7 @@ void ChromeMainDelegate::PreSandboxStart
     breakpad::InitCrashReporter(process_type);
 #endif  // defined(OS_ANDROID)
   }
-#endif  // defined(OS_POSIX) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 
   // After all the platform Breakpads have been initialized, store the command
   // line for crash reporting.
@@ -933,7 +933,7 @@ bool ChromeMainDelegate::DelaySandboxIni
 #endif
   return process_type == switches::kRelauncherProcess;
 }
-#elif defined(OS_POSIX) && !defined(OS_ANDROID)
+#elif defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 void ChromeMainDelegate::ZygoteStarting(
     ScopedVector<content::ZygoteForkDelegate>* delegates) {
 #if defined(OS_CHROMEOS)
