PORTNAME=	runj
DISTVERSION=	g20210506
CATEGORIES=	sysutils

MAINTAINER=	gijs@peskens.net
COMMENT=	Experimental, proof-of-concept OCI-compatible runtime for jails

LICENSE=	APACHE20 BSD2CLAUSE BSD3CLAUSE MIT
LICENSE_COMB=	multi

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	gizahNL
GH_TAGNAME=	3787843

.include "Makefile.deps"

GO_TARGET=	./cmd/runj \
		./cmd/runj-entrypoint \
		./cmd/containerd-shim-runj-v1

PLIST_FILES=	bin/runj \
		bin/runj-entrypoint \
		bin/containerd-shim-runj-v1

.include <bsd.port.mk>
