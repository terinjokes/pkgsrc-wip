# $NetBSD$
#
###########################################################
#                  Generated by fbsd2pkg                  #
#              Wed May 11 08:14:16 CDT 2016               #
###########################################################

###########################################################
# Unconverted and partially converted FreeBSD port syntax:

# TEST_DEPENDS=	bash:${PORTSDIR}/shells/bash
# Unknown tool: USE_TOOLS=	autoreconf
#USE_LDCONFIG=	yes
#OPTIONS_DEFINE=		CURL
#OPTIONS_DEFAULT=	CURL
#CURL_DESC=		Use libcurl for network file access (HTTPS and S3 support).
# CURL_LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl
#CURL_CONFIGURE_ENABLE=	libcurl
#PLIST_SUB=	PORTVERSION="${PORTVERSION}"
#TEST_TARGET=	test

DISTNAME=	htslib-${PORTVERSION}
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=samtools/}
GITHUB_PROJECT=	htslib
GITHUB_TAG=	${PORTVERSION}

MAINTAINER=	bacon4000@gmail.com
HOMEPAGE=	http://www.htslib.org/
COMMENT=	C library for high-throughput sequencing data formats
# LICENSE=	${WRKSRC}/LICENSE

# Test and change if necessary.
# MAKE_JOBS_SAFE=	no

# Just assuming C and C++: Adjust this!
USE_LANGUAGES=	c c++
USE_TOOLS+=	autoconf automake autoreconf gmake perl:test
GNU_CONFIGURE=	yes
REPLACE_PERL=	test/compare_sam.pl test/test.pl test/test_view.pl

SUBST_CLASSES+=		version
SUBST_STAGE.version=	post-patch
SUBST_SED.version+=	-e 's|@PORTVERSION@|${PORTVERSION}|g'
SUBST_FILES.version+=	${WRKSRC}/configure.ac

CPPFLAGS+=	-I${LOCALBASE}/include

# Check this
MAKE_ENV=	INSTALL_LIB="${INSTALL_LIB}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_DIR="${MKDIR}"

PORTVERSION=	1.3
SITE_PERL=	${PREFIX}/share
DATADIR=	${PREFIX}/share/htslib
DOCSDIR=	${PREFIX}/share/doc/htslib
EXAMPLESDIR=	${PREFIX}/share/examples/htslib

pre-configure:
	cd ${WRKSRC} && autoreconf

# Convert any _DEPENDS above that have a buildlink3.mk
# .include "../..///buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
