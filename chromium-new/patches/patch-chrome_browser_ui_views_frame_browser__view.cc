$NetBSD$

--- chrome/browser/ui/views/frame/browser_view.cc.orig	2016-06-24 01:02:14.000000000 +0000
+++ chrome/browser/ui/views/frame/browser_view.cc
@@ -187,7 +187,7 @@
 #include "content/public/common/mojo_shell_connection.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/native_theme/native_theme_dark_aura.h"
 #endif
 
@@ -1977,7 +1977,7 @@ void BrowserView::OnThemeChanged() {
 #if defined(OS_WIN)
     ui::NativeThemeDarkWin::instance()->NotifyObservers();
     ui::NativeThemeWin::instance()->NotifyObservers();
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
     ui::NativeThemeDarkAura::instance()->NotifyObservers();
     ui::NativeThemeAura::instance()->NotifyObservers();
 #endif
