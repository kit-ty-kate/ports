PORTNAME=	docker-engine
PORTVERSION=	g20210630
CATEGORIES=	sysutils

MAINTAINER=	gijs@peskens.net
COMMENT=	Docker Engine based on moby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash

RUN_DEPENDS=	containerd:sysutils/containerd \
		runj:sysutils/runj

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	kit-ty-kate
GH_PROJECT=	moby
GH_TAGNAME=	a3fce534e7
GH_SUBDIR=	src/github.com/docker/docker

GO_PKGNAME=	github.com/docker/docker
GO_TARGET=	./bin/dockerd

MAKE_ENV+=	DOCKER_GITCOMMIT=${GH_TAGNAME}

PLIST_FILES=	bin/dockerd

do-build:
	@cd ${GO_WRKSRC} && ${SETENV} ${MAKE_ENV} ${GO_ENV} ./hack/make.sh binary

.include <bsd.port.mk>
