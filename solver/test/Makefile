main: main-test.c print-sudoku.o sudoku-test.o
	gcc -o main -Wall -Wextra -Werror main-test.c print-sudoku.o sudoku-test.o

print-sudoku.o: print-sudoku.c
	gcc -c -Wall -Wextra -Werror print-sudoku.c

sudoku.o: sudoku-test.c
	gcc -c -Wall -Wextra -Werror sudoku-test.c

clean:
	rm -f *.o
	rm -f ${DEP}
	rm -f ${PRG}
	rm main
	rm -f *.gch
