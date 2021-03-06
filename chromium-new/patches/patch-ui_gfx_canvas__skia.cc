$NetBSD$

--- ui/gfx/canvas_skia.cc.orig	2016-06-24 01:02:53.000000000 +0000
+++ ui/gfx/canvas_skia.cc
@@ -246,7 +246,7 @@ void Canvas::DrawStringRectWithShadows(c
     Range range = StripAcceleratorChars(flags, &adjusted_text);
     bool elide_text = ((flags & NO_ELLIPSIS) == 0);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // On Linux, eliding really means fading the end of the string. But only
     // for LTR text. RTL text is still elided (on the left) with "...".
     if (elide_text) {
