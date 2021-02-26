# $FreeBSD$

PORTNAME=	wireguard-tools
PORTVERSION=	1.0.20210223
CATEGORIES=	net net-vpn
MASTER_SITES=	https://git.zx2c4.com/wireguard-tools/snapshot/

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Fast, modern and secure VPN Tunnel

LICENSE=	GPLv2
LICENSE_FILE=	${WRKDIR}/${DISTNAME}/COPYING

FLAVORS=	default kernel
kernel_PKGNAMESUFFIX=	-kernel

USES=		gmake tar:xz
USE_RC_SUBR=	wireguard_userland

WRKSRC=		${WRKDIR}/${DISTNAME}/src

MAKE_ARGS+=	DEBUG=no WITH_BASHCOMPLETION=yes WITH_SYSTEMDUNITS=no
MAKE_ENV+=	MANDIR="${MANPREFIX}/man" \
		SYSCONFDIR="${PREFIX}/etc"

OPTIONS_DEFINE=	WGQUICK
OPTIONS_DEFAULT=WGQUICK
OPTIONS_SUB=	yes

WGQUICK_DESC=		wg-quick(8) userland utility
WGQUICK_RUN_DEPENDS=	bash:shells/bash \
			wireguard-go:net/wireguard-go
WGQUICK_MAKE_ARGS=	WITH_WGQUICK=yes
WGQUICK_MAKE_ARGS_OFF=	WITH_WGQUICK=no

.if ${FLAVOR:U} == kernel
USE_RC_SUBR=	wireguard_kernel
OPTIONS_EXCLUDE=WGQUICK
COMMENT+=	(kernel flavor)
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/completion/wg-quick.bash-completion \
		${WRKSRC}/wg-quick/freebsd.bash

.include <bsd.port.mk>
