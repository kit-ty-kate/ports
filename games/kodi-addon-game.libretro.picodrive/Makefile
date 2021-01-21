# Created by: Rozhuk Ivan <rozhuk.im@gmail.com>
# $FreeBSD$

PORTNAME=	game.libretro.picodrive
PORTVERSION=	1.97.0.19
DISTVERSIONSUFFIX=	-Matrix
CATEGORIES=	games
PKGNAMEPREFIX=	kodi-addon-

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Kodi game addon for Sega - MS/MD/CD/32X (PicoDrive)

# TODO: check which LICENSE this is
LICENSE_FILE=	${WRKSRC}/depends/common/picodrive/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/kodi/AddonBase.h:multimedia/kodi
LIB_DEPENDS=	libtinyxml.so:textproc/tinyxml
RUN_DEPENDS=	kodi:multimedia/kodi \
		kodi-addon-game.libretro>=0:games/kodi-addon-game.libretro

USES=		cmake:noninja gmake
USE_GITHUB=	yes
GH_ACCOUNT=	kodi-game

# Keep in sync with: depends/common/picodrive/picodrive.txt and work/picodrive-*/.gitmodules
GH_TUPLE=	libretro:picodrive:046371ad2a3842d938cc74db5a615764ca2ff4ac:libretro_picodrive \
		notaz:libpicofe:76e45c3489a0c32d91744413c198f685b553f6c0:notaz_libpicofe/platform/libpicofe \
		notaz:cyclone68000:94a9d9a888e72cbfa4db12113cd113cf5e154f7f:notaz_cyclone68000/cpu/cyclone \
		digital-sound-antiques:emu2413:a18c81927fae4963f88a4c946ca150246cb9e9be:digital_sound_antiques_emu2413/pico/sound/emu2413 \
		lieff:minimp3:ef9e212fa29bb72d23558da21bb5694fd2d01768:lieff_minimp3/platform/common/minimp3

PLIST_SUB=	SOVERSION=${PORTVERSION}

CMAKE_ARGS=	-DCMAKE_BUILD_TYPE=Release \
		-DBUILD_SHARED_LIBS=1 \
		-DADDONS_TO_BUILD=${PORTNAME} \
		-DPICODRIVE_LIB=depends/common/picodrive/picodrive_libretro.so

post-extract:
	@${MV} ${WRKSRC_libretro_picodrive}/* ${WRKSRC}/depends/common/picodrive/

post-patch:
	@${REINPLACE_CMD} -e 's|find_library(PICODRIVE_LIB.*|add_subdirectory(depends/common/picodrive)|g' \
		${WRKSRC}/CMakeLists.txt

post-install:
	rm -rf ${STAGEDIR}${PREFIX}/lib/libretro

.include <bsd.port.mk>
