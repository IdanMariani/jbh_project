#ifndef GENERAL_H
#define GENERAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "server.h"

#define ARR_SIZE(_a) sizeof(_a) / sizeof(_a[0])
#define MAX_BUFFER 1024

typedef struct
{
    char first_name[30];
    char last_name[30];
    char id[10];
    char phone[11];
    float debt;
    char date[12];
} Customer;

enum Compiler
{
    COMP_LOCAL,
    COMP_SERVER,
};

void prompt_menu(bool *first_time);
void sort_list(Customer *customers, int length);
void switch_to_lower(char *buffer);
bool spaces_count(char *string, int index);

void cb_print_local(char *str);
void cb_print_server(char *buffer);
void print_list_new(Customer *list, int new_list_length, void(*callback)(char *));


#endif