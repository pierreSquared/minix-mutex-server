# Makefile for IPC server
PROG=	cs
SRCS=	main.c lock.c queue.c sender.c wait.c

DPADD+=	${LIBSYS}
LDADD+=	-lsys

MAN=

BINDIR?= /usr/sbin
FILES=cs.conf
FILESNAME=cs
FILESDIR= /etc/system.conf.d

.include <minix.service.mk>
