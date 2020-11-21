--- src/base/ThreadBase.cpp.orig	2020-11-21 14:52:20 UTC
+++ src/base/ThreadBase.cpp
@@ -28,7 +28,6 @@
 #define _GNU_SOURCE _GNU_SOURCE
 #endif
 
-#include <sys/prctl.h>
 #include <unistd.h>
 
 namespace base {
