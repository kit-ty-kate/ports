# $FreeBSD$

PORTNAME=	wireguard-kmod
PORTVERSION=	0.0.20210317
CATEGORIES=	net
MASTER_SITES=	https://git.zx2c4.com/wireguard-freebsd/snapshot/
DISTNAME=	wireguard-freebsd-367c27cb023e84226c2b54ef5f594997f8e4d70a

MAINTAINER=	decke@FreeBSD.org
COMMENT=	WireGuard implementation for the FreeBSD kernel

LICENSE=	MIT
LICENSE_FILE=	${WRKDIR}/${DISTNAME}/COPYING

IGNORE_FreeBSD_11=	only for FreeBSD 12.1 and newer

USES=		kmod tar:xz uidfix

WRKSRC=		${WRKDIR}/${DISTNAME}/src

PLIST_FILES=	${KMODDIR}/if_wg.ko

.include <bsd.port.mk>
