# $NetBSD: Makefile,v 1.6 2013/12/06 12:41:37 noud4 Exp $
#

DISTNAME=	gwget-1.0.4
PKGREVISION=	4
CATEGORIES=	gnome net
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gwget/1.0/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://projects.gnome.org/gwget/
COMMENT=	GNOME wget front-end
LICENSE=	gnu-gpl-v2

DEPENDS+=	wget>=1.12:../../net/wget

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool msgfmt gmake

GCONF_SCHEMAS+=	gwget.schemas

pre-configure:
	${LN} -s ${WRKSRC}/data/gwget.schemas ${WRKSRC}/gwget.schemas

.include "options.mk"

.include "../../devel/GConf/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
