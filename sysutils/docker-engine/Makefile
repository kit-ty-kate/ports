PORTNAME=	docker-engine
PORTVERSION=	g20210506#forked upstream master @30-04-2021 #59751bb23395a137253ca0b4fb99058ecec5a569
DISTVERSIONPREFIX=	v
DISTVERSIONSUFFIX=	-ce
CATEGORIES=	sysutils

MAINTAINER=	gijs@peskens.net
COMMENT=	Docker Engine based on moby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go>=1.12:lang/go \
		bash:shells/bash

RUN_DEPENDS=	containerd:sysutils/containerd \
		runj:sysutils/runj

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	gizahNL
GH_PROJECT=	moby
GH_TAGNAME=	02e304a
GH_SUBDIR=	src/github.com/docker/docker

GO_PKGNAME=	github.com/docker/docker

GO_TARGET=	./bin/dockerd
PLIST_FILES=	bin/dockerd

do-build:
	@cd ${GO_WRKSRC} && export DOCKER_GITCOMMIT=${GH_TAGNAME} && ${SETENV} ${MAKE_ENV} ${GO_ENV} ./hack/make.sh binary

.include <bsd.port.mk>
