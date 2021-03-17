# $FreeBSD$

PORTNAME=	wireguard-kmod
PORTVERSION=	0.0.20210317
CATEGORIES=	net
MASTER_SITES=	https://git.zx2c4.com/wireguard-freebsd/snapshot/
DISTNAME=	wireguard-freebsd-v${PORTVERSION}

MAINTAINER=	decke@FreeBSD.org
COMMENT=	WireGuard implementation for the FreeBSD kernel

LICENSE=	BSD2CLAUSE

USES=		kmod tar:xz

PLIST_FILES=	${KMODDIR}/if_wg.ko

.include <bsd.port.mk>
