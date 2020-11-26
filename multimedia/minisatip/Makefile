# Created by: Bernhard Froehlich <decke@FreeBSD.org>
# $FreeBSD$

PORTNAME=	minisatip
PORTVERSION=	1.0.4
CATEGORIES=	multimedia

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Multi-threaded SATIP server that supports DVB cards

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
LIB_DEPENDS=	libdvbcsa.so:multimedia/libdvbcsa

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	catalinii

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GNU_CONFIGURE=	yes
ALL_TARGET=	minisatip

PLIST_FILES=	bin/minisatip

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/minisatip ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
