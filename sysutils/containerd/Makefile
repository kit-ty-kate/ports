PORTNAME=	containerd
DISTVERSION=	g20210506
CATEGORIES=	sysutils

MAINTAINER=	decke@FreeBSD.org
COMMENT=	containerd part of docker

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash
USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	containerd
GH_SUBDIR=	src/github.com/containerd/containerd
GH_TAGNAME=	14316794ad0a33b8688078f770655c9203e4d80d

PLIST_FILES=	bin/containerd \
		bin/containerd-shim \
		bin/containerd-stress \
		bin/ctr
do-build:
	@cd ${WRKSRC} && ${MAKE_CMD}

do-install:
	@echo "${WRKSRC} && DESTDIR=${STAGEDIR}/${PREFIX} ${MAKE_CMD} install"
	@cd ${WRKSRC} && DESTDIR="${STAGEDIR}/${PREFIX}" ${MAKE_CMD} install

.include <bsd.port.mk>
