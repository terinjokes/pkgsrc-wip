# $NetBSD: Makefile,v 1.5 2015/09/16 15:50:07 outpaddling Exp $

###########################################################
#               Generated by fbsd2pkg                     #
###########################################################

###########################################################
# Unconverted and partially converted FreeBSD port syntax:

## Requires 64-bit long
#NOT_FOR_ARCHS=	i386

DISTNAME=	blasr_libcpp-${PORTVERSION}
CATEGORIES=	biology
# FreeBSD MASTER_SITE_SUBDIR:
MASTER_SITES=	http://acadix.biz/Ports/distfiles/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	bacon4000@gmail.com

COMMENT=	Library for analyzing PacBio sequences
# Double-check this
LICENSE=	modified-bsd

# Not needed yet, but developers don't want to support CentOS 6
# with it's GCC 4.4.
# GCC_REQD=	4.9 4.8

# Pessimistic assumption.  Test and change if possible.
# MAKE_JOBS_SAFE=	no

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake bash:run

# Broken: hdf5-c++>=1.8:../../devel/hdf5-c++

SUBST_CLASSES+=		bash
SUBST_STAGE.bash=	post-patch
SUBST_FILES.bash=	${WRKSRC}/makefile
SUBST_SED.bash=		-e 's|/bin/bash|${TOOLS_BASH}|g'

SUBST_CLASSES+=		pbbam
SUBST_STAGE.pbbam=	post-configure
SUBST_FILES.pbbam=	${WRKSRC}/libconfig.h
SUBST_SED.pbbam=	-e 's|define|undef|'

SUBST_CLASSES+=gcc44
SUBST_STAGE.gcc44=	post-patch
SUBST_FILES.gcc44=	${WRKSRC}/*/*
SUBST_SED.gcc44=	-e 's|c++11|c++0x|g' \

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == Darwin
SUBST_CLASSES+=		headers
SUBST_STAGE.headers=	post-patch
SUBST_FILES.headers=	hdf/*.hpp pbdata/saf/*.hpp
SUBST_SED.headers=	-e 's|\<cstdint\>|\<stdint.h\>|g' \
			-e 's|\<cinttypes\>|\<inttypes.h\>|g'
SUBST_CLASSES+=		uintmax
SUBST_STAGE.uintmax=	post-patch
SUBST_FILES.uintmax=	${WRKSRC}/alignment/suffixarray/SuffixArray.hpp
SUBST_SED.uintmax=	-e 's|UINT_MAX|INT_MAX|g'
.endif

# XXX buildlink should take care of this for you
CXXFLAGS+=	-I${PREFIX}/include -O
MAKE_FILE=	makefile

PORTNAME=	blasr_libcpp
PORTVERSION=	2015.08.17

# You may need this, especially if using do-install.
# Note: Depends on PLIST.
#AUTO_MKDIRS=	yes

do-configure:
	cd ${WRKSRC} && ./configure.py --no-pbbam \
		HDF5_INCLUDE=${PREFIX}/include HDF5_LIB=${PREFIX}/lib

do-install:
# XXX I suggest using pax(1) instead of this
	${MKDIR} ${DESTDIR}${PREFIX}/include ${DESTDIR}${PREFIX}/lib
	cd ${WRKSRC} && for fn in `find . -name '*.h' -o -name '*.hpp'`; do \
		dir=`dirname $$fn | cut -d / -f 2-`; \
		${MKDIR} ${DESTDIR}${PREFIX}/include/${PORTNAME}/$$dir; \
		${INSTALL_DATA} $$fn ${DESTDIR}${PREFIX}/include/${PORTNAME}/$$dir; \
	done
	for fn in `find ${WRKSRC} -name '*.a'`; do \
		${INSTALL_DATA} $$fn ${DESTDIR}${PREFIX}/lib; \
	done

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../devel/hdf5-c++/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
