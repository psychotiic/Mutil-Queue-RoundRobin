build:
	gcc -o Schedule main.c processQueue.c -std=c99

memcheck:
	valgrind --leak-check=full ./Schedule

clean:
	rm Schedule
