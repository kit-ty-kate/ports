PORTNAME=	humanlog
DISTVERSION=	0.5.0
CATEGORIES=	misc

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Logs in JSON or logfmt for humans to read

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	aybabtme

GO_TARGET=	./cmd/humanlog

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
