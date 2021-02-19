# $FreeBSD$

PORTNAME=	wireguard
PORTVERSION=	1.0
PORTEPOCH=	1
CATEGORIES=	net net-vpn

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Fast, modern and secure VPN Tunnel (meta-port)

RUN_DEPENDS=	wireguard-go:net/wireguard-go \
		wg:net/wireguard-tools

USES=		metaport

USE_RC_SUBR=	${PORTNAME}

.include <bsd.port.mk>
