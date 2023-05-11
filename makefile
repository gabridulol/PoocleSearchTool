all:
	gcc main.c sources/TF-IDF.c sources/searchTerm.c sources/PATRICIA.c sources/fileManagement.c -o e
	./e