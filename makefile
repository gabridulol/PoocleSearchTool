all:
    ifneq ($(wildcard builddir),)
		./builddir/demo
    else
		meson setup builddir; \
		cd builddir; \
		ninja; \
		./demo
    endif