all:
	gcc main.c sources/docList.c sources/index.c sources/wordle.c sources/patTree.c sources/fileManagement.c sources/searchEngineTasks.c sources/poocleMenu.c GTKProject/GTKProject.c -o e
	./e