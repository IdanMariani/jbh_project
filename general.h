#ifndef GENERAL_H
#define GENERAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


typedef struct
{
    char first_name[30];
    char last_name[30];
    char id[10];
    char phone[11];
    float debt;
    char date[12];
} Customer;

void prompt_menu(bool *first_time);
void sort_list(Customer *customers, int length);




#endif