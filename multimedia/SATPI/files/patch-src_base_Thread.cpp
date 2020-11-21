--- src/base/Thread.cpp.orig	2020-11-21 14:52:20 UTC
+++ src/base/Thread.cpp
@@ -29,7 +29,6 @@
 #define _GNU_SOURCE _GNU_SOURCE
 #endif
 
-#include <sys/prctl.h>
 #include <unistd.h>
 
 namespace base {
@@ -120,7 +119,7 @@ namespace base {
 	}
 
 	int Thread::getScheduledAffinity() const {
-		return sched_getcpu();
+		return 0;
 	}
 
 	bool Thread::setPriority(const Priority priority) {
@@ -153,7 +152,11 @@ namespace base {
 		const int minPriority = sched_get_priority_min(policy);
 		const int maxPriority = sched_get_priority_max(policy);
 		const int linuxPriority = minPriority + ((maxPriority - minPriority) * factor);
+#ifdef pthread_setschedprio
 		return (pthread_setschedprio(_thread, linuxPriority) == 0);
+#else
+		return (pthread_setprio(_thread, linuxPriority) == 0);
+#endif
 	}
 
 	void Thread::threadEntryBase() {
