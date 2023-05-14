all:
	gcc main.c sources/docList.c sources/TF-IDF.c sources/searchTerm.c sources/PATRICIA.c sources/fileManagement.c sources/searchEngineTasks.c sources/poocleMenu.c -o e
	./e