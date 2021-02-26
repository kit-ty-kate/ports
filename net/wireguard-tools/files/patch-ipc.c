--- ipc.c.orig	2021-02-23 18:32:18 UTC
+++ ipc.c
@@ -44,6 +44,8 @@ static int string_list_add(struct string_list *list, c
 #include "ipc-linux.h"
 #elif defined(__OpenBSD__)
 #include "ipc-openbsd.h"
+#elif defined(__FreeBSD__)
+#include "ipc-freebsd.h"
 #endif
 
 /* first\0second\0third\0forth\0last\0\0 */
