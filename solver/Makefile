main: main.c print_sudoku.o sudoku.o
	gcc -o main -Wall -Wextra -Werror main.c print_sudoku.o sudoku.o

print_sudoku.o: print-sudoku.h print-sudoku.c
	gcc -c -o print-sudoku.o -Wall -Wextra -Werror print-sudoku.h print-sudoku.h

sudoku.o: sudoku.h sudoku.c
	gcc -c -o sudoku.o -Wall -Wextra -Werror sudoku.h sudoku.c

clean:
	rm -f *.o
	rm -f ${DEP}
	rm -f ${PRG}
