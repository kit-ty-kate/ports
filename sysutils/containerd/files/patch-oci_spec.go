Patch default mountpoints for FreeBSD

Submitted by:	Gijs Peskens 
--- oci/spec.go.orig	2021-05-03 20:52:36 UTC
+++ oci/spec.go
@@ -161,50 +161,6 @@ func populateDefaultUnixSpec(ctx context.Context, s *S
 				},
 			},
 		},
-		Mounts: []specs.Mount{
-			{
-				Destination: "/proc",
-				Type:        "proc",
-				Source:      "proc",
-				Options:     []string{"nosuid", "noexec", "nodev"},
-			},
-			{
-				Destination: "/dev",
-				Type:        "tmpfs",
-				Source:      "tmpfs",
-				Options:     []string{"nosuid", "strictatime", "mode=755", "size=65536k"},
-			},
-			{
-				Destination: "/dev/pts",
-				Type:        "devpts",
-				Source:      "devpts",
-				Options:     []string{"nosuid", "noexec", "newinstance", "ptmxmode=0666", "mode=0620", "gid=5"},
-			},
-			{
-				Destination: "/dev/shm",
-				Type:        "tmpfs",
-				Source:      "shm",
-				Options:     []string{"nosuid", "noexec", "nodev", "mode=1777", "size=65536k"},
-			},
-			{
-				Destination: "/dev/mqueue",
-				Type:        "mqueue",
-				Source:      "mqueue",
-				Options:     []string{"nosuid", "noexec", "nodev"},
-			},
-			{
-				Destination: "/sys",
-				Type:        "sysfs",
-				Source:      "sysfs",
-				Options:     []string{"nosuid", "noexec", "nodev", "ro"},
-			},
-			{
-				Destination: "/run",
-				Type:        "tmpfs",
-				Source:      "tmpfs",
-				Options:     []string{"nosuid", "strictatime", "mode=755", "size=65536k"},
-			},
-		},
 		Linux: &specs.Linux{
 			MaskedPaths: []string{
 				"/proc/acpi",
@@ -237,6 +193,7 @@ func populateDefaultUnixSpec(ctx context.Context, s *S
 			Namespaces: defaultUnixNamespaces(),
 		},
 	}
+	s.Mounts = defaultMounts()
 	return nil
 }
 
