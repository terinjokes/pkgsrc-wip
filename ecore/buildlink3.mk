# $NetBSD: buildlink3.mk,v 1.6 2007/04/29 12:51:35 grzela1 Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
ECORE_BUILDLINK3_MK:=	${ECORE_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	ecore
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Necore}
BUILDLINK_PACKAGES+=	ecore
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}ecore

.if ${ECORE_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.ecore+=	ecore>=0.9.9.037
BUILDLINK_PKGSRCDIR.ecore?=	../../wip/ecore
.endif	# ECORE_BUILDLINK3_MK

.include	"../../wip/evas/buildlink3.mk"
.include	"../../x11/libXdamage/buildlink3.mk"
.include	"../../x11/libXp/buildlink3.mk"
.include	"../../x11/libXScrnSaver/buildlink3.mk"
.include	"../../www/curl/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
