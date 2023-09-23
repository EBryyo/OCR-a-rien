main: image.o label.o main.c
	gcc -Wall -Wextra -Werror -o main image.o label.o main.c

image.o: image/image.c
	gcc -Wall -Wextra -Werror -c image/image.c

label.o: image/image.c
	gcc -Wall -Wextra -Werror -c label/label.c

clean:
	rm *.o
	rm main
