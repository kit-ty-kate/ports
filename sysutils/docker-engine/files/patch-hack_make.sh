--- hack/make.sh.orig	2021-05-06 11:52:52 UTC
+++ hack/make.sh
@@ -142,14 +142,9 @@ bundle() {
 main() {
 	bundle_dir="bundles"
 	if [ -n "${PREFIX}" ]; then
-		bundle_dir="${PREFIX}/${bundle_dir}"
+		bundle_dir="${GOPATH}/bin"
 	fi
 
-	if [ -z "${KEEPBUNDLE-}" ]; then
-		echo "Removing ${bundle_dir}/"
-		rm -rf "${bundle_dir}"/*
-		echo
-	fi
 	mkdir -p "${bundle_dir}"
 
 	if [ $# -lt 1 ]; then
@@ -158,7 +153,7 @@ main() {
 		bundles=($@)
 	fi
 	for bundle in ${bundles[@]}; do
-		export DEST="${bundle_dir}/$(basename "$bundle")"
+		export DEST="${bundle_dir}/"
 		# Cygdrive paths don't play well with go build -o.
 		if [[ "$(uname -s)" == CYGWIN* ]]; then
 			export DEST="$(cygpath -mw "$DEST")"
