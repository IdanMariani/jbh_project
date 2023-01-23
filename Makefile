main: main.o read_csv.o validate.o general.o select_operator.o option_menu.o
	gcc main.o read_csv.o validate.o general.o select_operator.o option_menu.o -o main

main.o: main.c
	gcc -Wall -g -c main.c

read_csv.o: read_csv.c
	gcc -Wall -g -c read_csv.c 

validate.o: validate.c
	gcc -Wall -g -c validate.c 

general.o: general.c
	gcc -Wall -g -c general.c

select_operator.o: select_operator.c
	gcc -Wall -g -c select_operator.c

option_menu.o: option_menu.c
	gcc -Wall -g -c option_menu.c

clean:
	@rm -f *.o main