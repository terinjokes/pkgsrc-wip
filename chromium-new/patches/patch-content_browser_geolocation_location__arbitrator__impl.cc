$NetBSD$

--- content/browser/geolocation/location_arbitrator_impl.cc.orig	2016-06-24 01:02:20.000000000 +0000
+++ content/browser/geolocation/location_arbitrator_impl.cc
@@ -163,7 +163,7 @@ LocationProvider* LocationArbitratorImpl
 }
 
 LocationProvider* LocationArbitratorImpl::NewSystemLocationProvider() {
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_FREEBSD) || defined(OS_NETBSD)
   return NULL;
 #else
   return content::NewSystemLocationProvider();
