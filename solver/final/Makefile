solver: main.c print-sudoku.o sudoku.o
	gcc -Wall -Wextra -Werror -o solver -Wall -Wextra -Werror main.c print-sudoku.o sudoku.o

print-sudoku.o: print-sudoku.c
	gcc -Wall -Wextra -Werror -c -Wall -Wextra -Werror print-sudoku.c

sudoku.o: sudoku.c
	gcc -Wall -Wextra -Werror -c -Wall -Wextra -Werror sudoku.c

clean:
	rm -f *.o
	rm -f ${DEP}
	rm -f ${PRG}
	rm solver
	rm -f *.gch
