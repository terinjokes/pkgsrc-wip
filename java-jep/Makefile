# $NetBSD: Makefile,v 1.8 2012/11/25 23:32:23 othyro Exp $
#

DISTNAME=		jep-2.24
PKGNAME=		java-jep-2.24
CATEGORIES=		math
MASTER_SITES=		http://www.singularsys.com/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.singularsys.com/jep/
COMMENT=		Java Mathematical Expression Parser

PKG_DESTDIR_SUPPORT=	destdir

NO_BUILD=		#defined

INSTALLATION_DIRS=	share/classpath

do-install:
	${INSTALL_DATA} ${WRKSRC}/jep-2.24.jar \
		${DESTDIR}${PREFIX}/share/classpath/jep.jar
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/java-jep/
	${CP} -rf ${WRKSRC}/doc/* ${DESTDIR}${PREFIX}/share/doc/java-jep/
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${PREFIX}/share/doc/java-jep/
	${CHMOD} ${SHAREMODE} ${DESTDIR}${PREFIX}/share/doc/java-jep/

.include "../../mk/bsd.pkg.mk"
