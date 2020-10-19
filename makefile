#compile the shit yo
install:
	gcc ./src/main.c -o ./main -lm -lpthread
	cp ./main /usr/bin/ttySnake
remove:
	rm /usr/bin/ttySnake
