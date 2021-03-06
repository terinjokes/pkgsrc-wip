# $NetBSD: Makefile,v 1.6 2015/06/06 20:44:44 krytarowski Exp $
#

DISTNAME=	gdm-3.18.2
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GITHUB:=GNOME/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Gnome Display Manager

DEPENDS+=	zenity>=2.16.0:../../wip/zenity

USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_TOOLS+=		automake autoconf autoreconf
BUILD_DEFS+=		VARBASE

USE_LANGUAGES=		c c++

.include "options.mk"

CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-dmconfdir=${PKG_SYSCONFDIR}/dm
CONFIGURE_ARGS+=	--with-sysconfsubdir=
CONFIGURE_ARGS+=	--with-prefetch=yes
CONFIGURE_ARGS+=	--without-plymouth
CONFIGURE_ARGS+=	--without-systemd
CONFIGURE_ARGS+=	--disable-systemd-journal
CONFIGURE_ENV+=		PREFIX=${PREFIX}
CONFIGURE_ENV+=		X11BASE=${X11BASE}
INSTALL_MAKE_FLAGS+=	${MAKE_FLAGS}
INSTALL_MAKE_FLAGS+=	GDM_CUSTOM_CONF=${EGDIR}/custom.conf
INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}
MAKE_ENV+=		CHMOD=${CHMOD:Q} CHOWN=${CHOWN:Q}

OWN_DIRS=		${PKG_SYSCONFDIR}/Init
OWN_DIRS+=		${PKG_SYSCONFDIR}/PostLogin
OWN_DIRS+=		${PKG_SYSCONFDIR}/PostSession
OWN_DIRS+=		${PKG_SYSCONFDIR}/PreSession
OWN_DIRS+=		${PKG_SYSCONFDIR}/dm
OWN_DIRS+=		${PKG_SYSCONFDIR}/modules
OWN_DIRS+=		${VARBASE}/gdm
OWN_DIRS+=		${VARBASE}/log/gdm

PKG_SYSCONFSUBDIR=	gdm
EGDIR=			${PREFIX}/share/examples/gdm
CONF_FILES=		${EGDIR}/custom.conf ${PKG_SYSCONFDIR}/data/custom.conf

RCD_SCRIPTS=		gdm

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		desktop
SUBST_MESSAGE.desktop=	Configuring GDM settings.
SUBST_STAGE.desktop=	pre-configure
SUBST_FILES.desktop=	config/default.desktop.in
#SUBST_FILES.desktop+=	config/gnome.desktop.in
SUBST_FILES.desktop+=	config/gdm.conf.in
SUBST_SED.desktop=	-e 's/^_//g'
SUBST_SED.desktop+=	-e 's|^User=gdm$$|User=${GDMOWN}|g'
SUBST_SED.desktop+=	-e 's|^Group=gdm$$|Group=${GDMGRP}|g'
SUBST_SED.desktop+=	-e 's|^\#GtkTheme=.*$$|GtkTheme=Clearlooks|g'
SUBST_SED.desktop+=	-e 's|^\#FirstVT=.*$$|FirstVT=5|g'
SUBST_SED.desktop+=	-e 's|^\#VTAllocation=.*$$|VTAllocation=true|g'
.if ${OPSYS} == "NetBSD"
SUBST_SED.desktop+=	-e 's|^\#Logo=.*$$|Logo=${PREFIX}/share/pixmaps/NetBSD.xpm|g'
.endif
.if ${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD"
SUBST_SED.desktop+=	-e 's|^\#RebootCommand=.*$$|RebootCommand=/sbin/shutdown -r now|g'
SUBST_SED.desktop+=	-e 's|^\#HaltCommand=.*$$|HaltCommand=/sbin/shutdown -p now|g'
.endif
SUBST_SED.desktop+=	-e 's|^PreFetchProgram=.*$$|PreFetchProgram=${PREFIX}/libexec/gdmprefetch @${PKG_SYSCONFDIR}/gdmprefetchlist|g'

SUBST_CLASSES+=		gdmsetup
SUBST_MESSAGE.gdmsetup=	Patching gdmsetup theme installer to use ${REAL_ROOT_USER}:${REAL_ROOT_GROUP}
SUBST_STAGE.gdmsetup=	post-patch
SUBST_FILES.gdmsetup=	gui/gdmsetup.c
SUBST_SED.gdmsetup=	-e 's/root:root/${REAL_ROOT_USER}:${REAL_ROOT_GROUP}/g'

.if ${OPSYS} == "SunOS"
CFLAGS+=	-DSunOS
GDMOWN=		daemon
GDMGRP=		other
.else
GDMOWN=		daemon
GDMGRP=		daemon
.endif

# The following forces the X server to start on the 5th virtual terminal.
# This is suboptimal but matches the defaults for the xdm configuration,
# which should work for most installations.  See the definition of
# DEFAULTVT in xsrc/xfree/xc/programs/xdm/config/Imakefile.
#
# If we do not do this, we hit a very annoying and obscure problem: during
# system startup, gdm starts before init spawns gettys.  If the X server
# is started before init spawns the gettys (which easily happens on slow
# machines), it grabs the first virtual terminal (instead of the first
# "free" one).  Later on, when the first getty is started, it grabs the
# same terminal X used (the first one).  As a result, only one of them
# will receive key presses.  And on slow machines, X will have lost access
# to the keyboard.
.if (${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD") && \
    (${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64")
CONFIGURE_ARGS+=	X_SERVER_ARGS="vt05"
.endif

PLIST_VARS+=		dmx
.if exists(${X11BASE}/include/X11/extensions/dmxext.h)
PLIST.dmx=		yes
.endif
PRINT_PLIST_AWK+=	/dmx/ { print "$${DMX}" $$0; next }

PLIST_VARS+=		gdmopen
.if exists(/usr/include/linux/vt.h) || ${OPSYS} == "SunOS"
PLIST.gdmopen=		yes
.endif
PRINT_PLIST_AWK+=	/gdmopen/ { print "$${GDMOPEN}" $$0; next }

pre-configure:
	sed -i -e 's,/usr/local,${PREFIX},g' \
		-e 's,/bin/bash,/bin/sh,g' \
		${WRKSRC}/daemon/gdm-session-worker.c &&
	cd ${WRKSRC}; \
		./autogen.sh; \
		autoreconf -fiv; \
		intltoolize
post-install:
	${INSTALL_DATA} ${FILESDIR}/NetBSD.xpm ${DESTDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${FILESDIR}/custom.desktop \
		${DESTDIR}${PREFIX}/share/gdm/BuiltInSessions

.include "../../audio/libcanberra/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../wip/accountsservice/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
BUILDLINK_API_DEPENDS.libart+=	libart>=2.3.11
.include "../../graphics/libart/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
