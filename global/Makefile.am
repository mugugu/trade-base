AUTOMAKE_OPTIONS = foreign
# 纯头文件库 - 不需要SUBDIRS
ACLOCAL_AMFLAGS = -I m4
AM_CPPFLAGS			=  -I$(top_srcdir) -I$(top_srcdir)/src -I$(top_srcdir)/src

# 头文件安装到模块子目录
install-data-local:
	$(MKDIR_P) '$(DESTDIR)$(includedir)/global'
	$(INSTALL_DATA) $(top_srcdir)/src/global.h '$(DESTDIR)$(includedir)/global/'

uninstall-local:
	rm -rf '$(DESTDIR)$(includedir)/global'

.PHONY: all install
all:
	@echo "Header-only library global - nothing to compile"

install: install-data-local

install: install-data-local
