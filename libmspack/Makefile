# $NetBSD: Makefile,v 1.1 2015/08/01 13:49:58 makoto Exp $

DISTNAME=	libmspack-0.5alpha
CATEGORIES=	devel
MASTER_SITES=	http://www.cabextract.org.uk/libmspack/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cabextract.org.uk/libmspack/
COMMENT=	Archiver for Microsoft format CAB, CHM, WIM, LIT, HLP, KWAJ and SZDD
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libmspack.pc.in

.include "../../mk/bsd.pkg.mk"
