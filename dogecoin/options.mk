# $NetBSD: options.mk,v 1.1 2014/09/22 11:18:54 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dogecoin
PKG_SUPPORTED_OPTIONS+=	miniupnpc qrcode qt tests
PKG_SUGGESTED_OPTIONS=	qt # blank
PLIST_VARS+=		qt tests

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mminiupnpc)
QMAKE_OPTIONS+=	USE_UPNP=1
.include "../../wip/miniupnpc/buildlink3.mk"
.else
QMAKE_OPTIONS+=	USE_UPNP=-
CONFIGURE_ARGS+=	--without-miniupnpc
.endif

.if !empty(PKG_OPTIONS:Mqrcode)
QMAKE_OPTIONS+=	USE_QRCODE=1
.include "../../converters/qrencode/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Minet6)
QMAKE_OPTIONS+=	USE_IPV6=0
.endif

.if !empty(PKG_OPTIONS:Mqt)
PLIST.qt=	yes
.include "../../x11/qt5-qtbase/buildlink3.mk"
QMAKE_OPTIONS+=	USE_DBUS=1 # XXX still needed?
.endif

.if empty(PKG_OPTIONS:Mqt)
CONFIGURE_ARGS+=	--without-gui
.endif

.if empty(PKG_OPTIONS:Mtests)
CONFIGURE_ARGS+=	--disable-tests
.else
PLIST.tests=	yes
.endif
