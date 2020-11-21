--- src/InterfaceAttr.cpp.orig	2020-11-21 14:52:20 UTC
+++ src/InterfaceAttr.cpp
@@ -95,6 +95,7 @@
 					GAI_PERROR("getnameinfo()", s);
 					continue;
 				}
+/* TODO: Fix for FreeBSD needed which does not support this ioctl
 				// Get hardware address
 				int fd = ::socket(AF_INET, SOCK_STREAM, 0);
 				if (fd == -1) {
@@ -122,6 +123,13 @@
 					foundInterface = true;
 					break;
 				}
+*/
+				// BEGIN CUSTOM HACK
+				_ifaceName = "";
+				_ipAddr = host;
+				foundInterface = true;
+				break;
+				// END CUSTOM HACK
 			}
 		}
 		// free linked list
