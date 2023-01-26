options:
	@echo Options: main, server, client

main: main.o read_csv.o validate.o general.o select_operator.o option_menu.o
	gcc main.o read_csv.o validate.o general.o select_operator.o option_menu.o -o main

server: server.o read_csv.o validate.o general.o select_operator.o option_menu.o
	gcc server.o read_csv.o validate.o general.o select_operator.o option_menu.o -lpthread -o server

client: client.o 
	gcc client.o -lpthread -o client

main.o: main.c
	gcc -Wall -g -c main.c

server.o: server.c
	gcc -Wall -g -c server.c

client.o: client.c
	gcc -Wall -g -c client.c

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
	@rm -f *.o main server client