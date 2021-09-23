all: driver


driver: src/driver.c src/BinarySearchTree.c
	mkdir bin
	gcc src/driver.c src/BinarySearchTree.c -Iincludes -o bin/driver

clean:
	rm -r bin
