all:
	gcc main.c sources/PATRICIA.c sources/TF-IDF.c -o e
	./e