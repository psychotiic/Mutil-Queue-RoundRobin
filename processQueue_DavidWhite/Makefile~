build:
	gcc -g -lpthread -o Schedule main.c processQueue.c -pthread -std=c99

memcheck:
	valgrind --leak-check=full ./Schedule

clean:
	rm Schedule
