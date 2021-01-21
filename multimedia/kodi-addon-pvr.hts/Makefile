# Created by: Bernhard Froehlich <decke@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pvr.hts
DISTVERSION=	8.2.2
DISTVERSIONSUFFIX=	-Matrix
CATEGORIES=	multimedia

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Tvheadend PVR addon for Kodi

LICENSE=	GPLv2+

LIB_DEPENDS=	libp8-platform.so:devel/p8-platform \
		libkodiplatform.so:devel/kodi-platform \
		libpugixml.so:textproc/pugixml

USES=		cmake:noninja compiler:c++17-lang kodi

USE_GITHUB=	yes
GH_ACCOUNT=	kodi-pvr

.include <bsd.port.mk>
