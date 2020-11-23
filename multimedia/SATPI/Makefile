# Created by: Bernhard Froehlich <decke@FreeBSD.org>
# $FreeBSD$

PORTNAME=	SATPI
PORTVERSION=	1.6.1
DISTVERSIONPREFIX=	V
CATEGORIES=	multimedia

MAINTAINER=	decke@FreeBSD.org
COMMENT=	SAT>IP server for low end devices

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
LIB_DEPENDS=	libdvbcsa.so:multimedia/libdvbcsa

USES=		compiler:c++11-lang gmake
USE_GITHUB=	yes
GH_ACCOUNT=	decke
GH_TAGNAME=	192be40

CFLAGS=		-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

ALL_TARGET=	satpi

PLIST_FILES=	bin/satpi

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/satpi ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
