all:
	gcc main.c sources/PATRICIA.c sources/TF-IDF.c sources/searchEnigineTasks.c sources/fileManagement.c -o e
	./e