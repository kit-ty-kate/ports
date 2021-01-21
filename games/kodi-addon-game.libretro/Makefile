# Created by: Rozhuk Ivan <rozhuk.im@gmail.com>
# $FreeBSD$

PORTNAME=	game.libretro
PORTVERSION=	2.2.0
DISTVERSIONSUFFIX=	-Matrix
CATEGORIES=	games
PKGNAMEPREFIX=	kodi-addon-

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Libretro compatibility layer for the Kodi Game API

LICENSE=	GPLv2+

BUILD_DEPENDS=	${LOCALBASE}/include/kodi/AddonBase.h:multimedia/kodi
LIB_DEPENDS=	libp8-platform.so:devel/p8-platform \
		libtinyxml.so:textproc/tinyxml
RUN_DEPENDS=	kodi:multimedia/kodi

USES=		cmake localbase compiler:c++14-lang
USE_CXXSTD=	c++14
USE_GITHUB=	yes
GH_ACCOUNT=	kodi-game

PLIST_SUB=	SOVERSION=${PORTVERSION}

.include <bsd.port.mk>
