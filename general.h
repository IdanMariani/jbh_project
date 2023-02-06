#ifndef GENERAL_H
#define GENERAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define ARR_SIZE(_a) sizeof(_a) / sizeof(_a[0])
#define MAX_BUFFER 1024
#define LOCAL 0
#define SERVER 1

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
void switch_to_lower(char *buffer);
bool spaces_count(char *string, int index);
void print_list(Customer *list, int new_list_length, int new_sock ,void (*callback)(char *,int));
void cb_print_local(char *str, int new_sock);
void cb_print_server(char *buffer, int new_sock);
void cb_error_local(char *buffer, int new_sock);
void cb_error_server(char *buffer, int new_sock);
void print_error(char *buffer,int new_sock, void (*callback)(char *, int));

#endif