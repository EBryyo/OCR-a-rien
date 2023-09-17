main: main.c print-sudoku.o sudoku.o
	gcc -o main -Wall -Wextra -Werror main.c print_sudoku.o sudoku.o

print-sudoku.o: print-sudoku.h print-sudoku.c
	gcc -c -Wall -Wextra -Werror print-sudoku.h print-sudoku.h

sudoku.o: sudoku.h sudoku.c
	gcc -c -Wall -Wextra -Werror sudoku.h sudoku.c

clean:
	rm -f *.o
	rm -f ${DEP}
	rm -f ${PRG}
	rm -f *.gch
