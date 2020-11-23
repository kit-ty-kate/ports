--- src/base/Thread.cpp.orig	2020-11-23 10:53:55 UTC
+++ src/base/Thread.cpp
@@ -123,7 +123,7 @@ namespace base {
 	}
 
 	int Thread::getScheduledAffinity() const {
-		return sched_getcpu();
+		return 0;
 	}
 
 	bool Thread::setPriority(const Priority priority) {
@@ -156,7 +156,11 @@ namespace base {
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
