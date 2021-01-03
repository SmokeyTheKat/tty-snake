#compile the shit yo
all:
	gcc ./src/main.c -o ./tty-snake -lm -lpthread
install: all
	sudo cp ./tty-snake /usr/bin/tty-snake
remove:
	sudo rm /usr/bin/tty-snake
