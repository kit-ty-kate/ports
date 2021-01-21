# Created by: Rozhuk Ivan <rozhuk.im@gmail.com>
# $FreeBSD$

PORTNAME=	game.libretro.genplus
PORTVERSION=	1.7.4.9
DISTVERSIONSUFFIX=	-Leia
CATEGORIES=	games
PKGNAMEPREFIX=	kodi-addon-

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Kodi game addon for Sega - MS/GG/MD/CD (Genesis Plus GX)

LICENSE_FILE=	${WRKSRC}/depends/common/genplus/LICENSE.txt

BUILD_DEPENDS=	${LOCALBASE}/include/kodi/AddonBase.h:multimedia/kodi
LIB_DEPENDS=	libtinyxml.so:textproc/tinyxml
RUN_DEPENDS=	kodi:multimedia/kodi \
		kodi-addon-game.libretro>=0:games/kodi-addon-game.libretro

USES=		cmake:noninja gmake
USE_GITHUB=	yes
GH_ACCOUNT=	kodi-game \
		libretro:genplus
GH_PROJECT=	Genesis-Plus-GX:genplus
# Keep in sync with: depends/common/genplus/genplus.txt
GH_TAGNAME=	50551066f71f8a5ea782ea3747891fd6d24ebe67:genplus

PLIST_SUB=	SOVERSION=${PORTVERSION}

CMAKE_ARGS=	-DCMAKE_BUILD_TYPE=Release \
		-DBUILD_SHARED_LIBS=1 \
		-DADDONS_TO_BUILD=${PORTNAME} \
		-DGENPLUS_LIB=depends/common/genplus/genesis_plus_gx_libretro.so

post-extract:
	@${MV} ${WRKSRC_genplus}/* ${WRKSRC}/depends/common/genplus/

post-patch:
	@${REINPLACE_CMD} -e 's|find_library(GENPLUS_LIB.*|add_subdirectory(depends/common/genplus)|g' \
		${WRKSRC}/CMakeLists.txt

post-install:
	rm -rf ${STAGEDIR}${PREFIX}/lib/libretro

.include <bsd.port.mk>
