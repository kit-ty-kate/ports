# Created by: Bernhard Froehlich <decke@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pvr.hts
DISTVERSION=	8.2.2
DISTVERSIONSUFFIX=	-Matrix
CATEGORIES=	multimedia
PKGNAMEPREFIX=	kodi-addon-

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Tvheadend PVR addon for Kodi

LICENSE=	GPLv2+

BUILD_DEPENDS=	${LOCALBASE}/include/kodi/addon-instance/PVR.h:multimedia/kodi
LIB_DEPENDS=	libp8-platform.so:devel/p8-platform \
		libkodiplatform.so:devel/kodi-platform \
		libpugixml.so:textproc/pugixml
RUN_DEPENDS=	kodi:multimedia/kodi

USES=		cmake:noninja compiler:c++17-lang

USE_GITHUB=	yes
GH_ACCOUNT=	kodi-pvr

.include <bsd.port.mk>
