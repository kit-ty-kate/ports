# Created by: Rozhuk Ivan <rozhuk.im@gmail.com>
# $FreeBSD$

PORTNAME=	game.libretro.picodrive
PORTVERSION=	1.97.0.19
DISTVERSIONSUFFIX=	-Matrix
CATEGORIES=	games
PKGNAMEPREFIX=	kodi-addon-

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Kodi game addon for Sega - MS/MD/CD/32X (PicoDrive)

LICENSE_FILE=	${WRKSRC}/depends/common/picodrive/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/kodi/AddonBase.h:multimedia/kodi
LIB_DEPENDS=	libtinyxml.so:textproc/tinyxml
RUN_DEPENDS=	kodi:multimedia/kodi \
		kodi-addon-game.libretro>=0:games/kodi-addon-game.libretro

USES=		cmake:noninja gmake
USE_GITHUB=	yes
GH_ACCOUNT=	kodi-game \
		libretro:picodrive
GH_PROJECT=	picodrive:picodrive
# Keep in sync with: depends/common/picodrive/picodrive.txt
GH_TAGNAME=	046371ad2a3842d938cc74db5a615764ca2ff4ac:picodrive

PLIST_SUB=	SOVERSION=${PORTVERSION}

CMAKE_ARGS=	-DCMAKE_BUILD_TYPE=Release \
		-DBUILD_SHARED_LIBS=1 \
		-DADDONS_TO_BUILD=${PORTNAME} \
		-DPICODRIVE_LIB=depends/common/picodrive/picodrive_libretro.so

post-extract:
	@${MV} ${WRKSRC_picodrive}/* ${WRKSRC}/depends/common/picodrive/

post-patch:
	@${REINPLACE_CMD} -e 's|find_library(PICODRIVE_LIB.*|add_subdirectory(depends/common/picodrive)|g' \
		${WRKSRC}/CMakeLists.txt

post-install:
	rm -rf ${STAGEDIR}${PREFIX}/lib/libretro

.include <bsd.port.mk>
