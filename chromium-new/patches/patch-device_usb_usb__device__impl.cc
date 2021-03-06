$NetBSD$

--- device/usb/usb_device_impl.cc.orig	2016-06-24 01:02:22.000000000 +0000
+++ device/usb/usb_device_impl.cc
@@ -20,7 +20,11 @@
 #include "device/usb/usb_descriptors.h"
 #include "device/usb/usb_device_handle_impl.h"
 #include "device/usb/usb_error.h"
+#if defined(OS_FREEBSD)
+#include "libusb.h"
+#else
 #include "third_party/libusb/src/libusb/libusb.h"
+#endif
 
 #if defined(OS_CHROMEOS)
 #include "chromeos/dbus/dbus_thread_manager.h"
