# $FreeBSD$

PORTNAME=	wireguard-kmod
PORTVERSION=	0.0.20210317
CATEGORIES=	net
MASTER_SITES=	https://git.zx2c4.com/wireguard-freebsd/snapshot/
DISTNAME=	wireguard-freebsd-v${PORTVERSION}

MAINTAINER=	decke@FreeBSD.org
COMMENT=	WireGuard implementation for the FreeBSD kernel

LICENSE=	MIT
LICENSE_FILE=	${WRKDIR}/${DISTNAME}/COPYING

USES=		kmod tar:xz

WRKSRC=		${WRKDIR}/${DISTNAME}/src

PLIST_FILES=	${KMODDIR}/if_wg.ko

.include <bsd.port.mk>
