--- src/base/Thread.h.orig	2020-11-21 14:52:20 UTC
+++ src/base/Thread.h
@@ -26,7 +26,6 @@
 
 #include <pthread.h>
 #include <unistd.h>
-#include <sys/prctl.h>
 
 namespace base {
 
