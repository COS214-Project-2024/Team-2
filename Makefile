main:
	g++ -g --std=c++17 *.cpp -o main

run:
	./main

clean:
	rm -f *.o main

clear:
	clear

l:
	valgrind ./main
