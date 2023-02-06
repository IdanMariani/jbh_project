# Project Title
Manage a Data Base Of Customers.

# Description
this program will read pre made customers from a csv file,
and make a sorted customers list by their debt (from low to high).
the user will be able to add new customers to the list,
or to check certin things with the right operator.
the user will be able to write in total 4 commands in the terminal
each customer will have 6 categories to choose from and
each category can use 4 diffrent operators. 

# Commands      # Categories      # Operators
- select        first name            "!="
- set           last name             "="
- print         id                    "<"
- quit          phone                 ">"
                debt                                
                date    

# How To Use
Step #1: run command:
make
Step #2: choose from 3 options:
local, server, client
# Make & Run Local
make local
.local customers.txt
# Make & Run Server And Client
make server
./server 1212 customers.txt
make client
.client 1212 127.0.0.1
# Delete .o files
run command:
make clean

# Examples for local
once the program has started write in terminal
the following commands for each of the different options

- select:
select first name=avi
select last name!=cohen"
select id>212366758
select phone=0548733611
select debt<-400
select date=07/06/2016

- set:
set first name=avi,last name=cohen,id=212366758,phone=0549987615,debt=-200,date=07/06/2016

- print:
print

- quit:
quit

# Examples for Server and Client
in this mode you will be able to send up to 5 messages
when you want to send to server all to messages
enter send
you can enter send at any point

# Author Info
idan mariani