# all:
#     ifneq ($(wildcard builddir),)
# 		./builddir/demo
#     else
# 		meson setup builddir; \
# 		cd builddir; \
# 		ninja; \
# 		./demo
#     endif
all:
	gcc main.c sources/docList.c sources/index.c sources/wordle.c sources/patTree.c sources/fileManagement.c sources/searchEngineTasks.c sources/poocleMenu.c -o e
	./e