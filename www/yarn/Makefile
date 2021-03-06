# $FreeBSD$

PORTNAME=	yarn
DISTVERSIONPREFIX=	v
DISTVERSION=	1.22.4
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://yarnpkg.com/downloads/${PORTVERSION}/

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	Package manager for node, alternative to npm

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFLICTS_INSTALL?=	yarn-node12 yarn-node10 yarn-node8

OPTIONS_DEFINE=	HADOOPCOMPAT
OPTIONS_SINGLE=	BACKEND
OPTIONS_SINGLE_BACKEND=	NODE10 NODE12 NODE
OPTIONS_DEFAULT=	NODE
HADOOPCOMPAT_DESC=	hadoop2 compatibility, the yarn script is excluded
NODE_DESC=	Use www/node as backend
NODE12_DESC=	Use www/node12 as backend
NODE10_DESC=	Use www/node10 as backend

OPTIONS_SUB=	yes

NODE_RUN_DEPENDS=	node>=0.8.0:www/node
NODE12_RUN_DEPENDS=	node12>=12.0.0:www/node12
NODE10_RUN_DEPENDS=	node10>=10.0.0:www/node10

HADOOPCOMPAT_CONFLICTS_INSTALL_OFF=	hadoop2*

NO_ARCH=	yes
NO_BUILD=	yes

post-patch:
	@${RM} ${WRKSRC}/bin/*.cmd
	@${REINPLACE_CMD} -i '' \
		-e 's|"installationMethod": "tar"|"installationMethod": "pkg"|g' \
		${WRKSRC}/package.json
	@${REINPLACE_CMD} -i '' -e 's%Linux)%Linux|FreeBSD|DragonFly)%g' \
		${WRKSRC}/bin/yarn

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/node_modules/yarn
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/node_modules/yarn)
	${RLN} ${STAGEDIR}${PREFIX}/lib/node_modules/yarn/bin/yarn.js \
		${STAGEDIR}${PREFIX}/bin/yarn.js
	${RLN} ${STAGEDIR}${PREFIX}/lib/node_modules/yarn/bin/yarnpkg \
		${STAGEDIR}${PREFIX}/bin/yarnpkg

do-install-HADOOPCOMPAT-off:
	${RLN} ${STAGEDIR}${PREFIX}/lib/node_modules/yarn/bin/yarn \
		${STAGEDIR}${PREFIX}/bin/yarn

.include <bsd.port.mk>
