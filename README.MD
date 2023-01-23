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
Step #2: run command:
./main customers.txt

to delete .o files
run command:
make clean

# Examples
once the program has started write in terminal
the following commands for each of the different options

- select:
select first name=avi
select last name!=cohen
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

# Author Info
idan mariani