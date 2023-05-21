all:
    ifneq ($(wildcard builddir),)
		./builddir/poocle
    else
		meson setup builddir; \
		cd builddir; \
		ninja; \
		./poocle
    endif