$NetBSD$

--- chrome/browser/ui/webui/about_ui.cc.orig	2016-06-24 01:02:14.000000000 +0000
+++ chrome/browser/ui/webui/about_ui.cc
@@ -73,7 +73,7 @@
 #include "chrome/browser/ui/webui/theme_source.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "content/public/browser/zygote_host_linux.h"
 #include "content/public/common/sandbox_linux.h"
 #endif
@@ -642,7 +642,7 @@ class AboutDnsHandler : public base::Ref
   DISALLOW_COPY_AND_ASSIGN(AboutDnsHandler);
 };
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 std::string AboutLinuxProxyConfig() {
   std::string data;
   AppendHeader(&data, 0,
@@ -658,6 +658,7 @@ std::string AboutLinuxProxyConfig() {
   return data;
 }
 
+#if !defined(OS_BSD)
 void AboutSandboxRow(std::string* data, int name_id, bool good) {
   data->append("<tr><td>");
   data->append(l10n_util::GetStringUTF8(name_id));
@@ -759,6 +760,7 @@ void AboutUIHTMLSource::StartDataRequest
     else if (path == kKeyboardUtilsPath)
       idr = IDR_KEYBOARD_UTILS_JS;
 #endif
+#endif
 
     response = ResourceBundle::GetSharedInstance().GetRawDataResource(
         idr).as_string();
@@ -769,7 +771,7 @@ void AboutUIHTMLSource::StartDataRequest
   } else if (source_name_ == chrome::kChromeUIDNSHost) {
     AboutDnsHandler::Start(profile(), callback);
     return;
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   } else if (source_name_ == chrome::kChromeUILinuxProxyConfigHost) {
     response = AboutLinuxProxyConfig();
 #endif
@@ -778,7 +780,7 @@ void AboutUIHTMLSource::StartDataRequest
     ChromeOSCreditsHandler::Start(path, callback);
     return;
 #endif
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_FREEBSD) && !defined(OS_NETBSD)
   } else if (source_name_ == chrome::kChromeUISandboxHost) {
     response = AboutSandbox();
 #endif
