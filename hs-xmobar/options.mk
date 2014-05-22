# $NetBSD: options.mk,v 1.2 2014/05/22 21:41:48 szptvlfn Exp $

PKG_OPTIONS_VAR=    PKG_OPTIONS.hs-xmobar
PKG_SUPPORTED_OPTIONS= xft2 datezone
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mxft2)
CONFIGURE_ARGS+=    --flags="with_xft"
.include "../../x11/hs-X11-xft/buildlink3.mk"
.else
.endif

# Support for other timezones.
.if !empty(PKG_OPTIONS:Mdatezone)
CONFIGURE_ARGS+=    --flags="with_datezone"
.include "../../wip/hs-timezone-olson/buildlink3.mk"
.include "../../wip/hs-timezone-series/buildlink3.mk"
.else
.endif
