--- src/base/ThreadBase.cpp.orig	2020-11-23 10:53:55 UTC
+++ src/base/ThreadBase.cpp
@@ -30,6 +30,10 @@
 
 #ifdef __linux__
 #include <sys/prctl.h>
+#include <sched.h>
+#elif __FreeBSD__
+#include <sys/param.h>
+#include <sys/cpuset.h>
 #endif
 
 #include <unistd.h>
@@ -94,16 +98,24 @@ namespace base {
 
 	void ThreadBase::setAffinity(int cpu) {
 		if (cpu > 0 && cpu < getNumberOfProcessorsOnline()) {
+#ifdef __linux__
 			cpu_set_t cpus;
 			CPU_ZERO(&cpus);
 			CPU_SET(cpu, &cpus);
 //			pthread_setaffinity_np(_thread, sizeof(cpu_set_t), &cpus);
 			sched_setaffinity(_thread, sizeof(cpu_set_t), &cpus);
+#elif __FreeBSD__
+			// TODO: FreeBSD support
+#endif
 		}
 	}
 
 	int ThreadBase::getScheduledAffinity() const {
+#ifdef __linux__
 		return sched_getcpu();
+#elif __FreeBSD__
+		// TODO: FreeBSD support
+#endif
 	}
 
 	bool ThreadBase::setPriority(const Priority priority) {
@@ -136,7 +148,13 @@ namespace base {
 		const int minPriority = sched_get_priority_min(policy);
 		const int maxPriority = sched_get_priority_max(policy);
 		const int linuxPriority = minPriority + ((maxPriority - minPriority) * factor);
+
+#ifdef __linux__
 		return (pthread_setschedprio(_thread, linuxPriority) == 0);
+#elif __FreeBSD__
+		// TODO: FreeBSD support
+		return 0;
+#endif
 	}
 
 	void ThreadBase::threadEntryBase() {
