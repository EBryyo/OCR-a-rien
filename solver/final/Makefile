main: main.c print-sudoku.o sudoku.o
	gcc -o main -Wall -Wextra -Werror main.c print-sudoku.o sudoku.o

print-sudoku.o: print-sudoku.c
	gcc -c -Wall -Wextra -Werror print-sudoku.c

sudoku.o: sudoku.c
	gcc -c -Wall -Wextra -Werror sudoku.c

clean:
	rm -f *.o
	rm -f ${DEP}
	rm -f ${PRG}
	rm main
	rm -f *.gch
