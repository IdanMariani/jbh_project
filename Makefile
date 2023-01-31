options:
	@echo Options: local, server, client

local: local.o read_csv.o validate.o general.o select_operator.o option_menu.o user_input.o
	gcc local.o read_csv.o validate.o general.o select_operator.o option_menu.o user_input.o -o local

server: server.o read_csv.o validate.o general.o select_operator.o option_menu.o user_input.o
	gcc server.o read_csv.o validate.o general.o select_operator.o option_menu.o user_input.o -lpthread -o server

client: client.o 
	gcc client.o -lpthread -o client

main.o: local.c
	gcc -Wall -g -c local.c

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

user_input.o: user_input.c
	gcc -Wall -g -c user_input.c

clean:
	@rm -f *.o local server client