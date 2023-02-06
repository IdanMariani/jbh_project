#ifndef SELECT_OPERATOR_H
#define SELECT_OPERATOR_H

#include "general.h"

bool fill_portion2_operator(int index, char *portion2);
void print_operator(Customer *list, int new_list_length, int index, char portion2, char *portion3, int comp, int new_sock);
void first_name_operator(Customer *list, int new_list_length, char portion2, char *portion3);
void last_name_operator(Customer *list, int new_list_length, char portion2, char *portion3);
void id_operator(Customer *list, int new_list_length, char portion2, char *portion3);
void phone_operator(Customer *list, int new_list_length, char portion2, char *portion3);
void debt_operator(Customer *list, int new_list_length, char portion2, char *portion3);
void date_operator(Customer *list, int new_list_length, char portion2, char *portion3);
void first_name_operator_server(Customer *list, int new_list_length, char portion2, char *portion3, int new_sock);
void last_name_operator_server(Customer *list, int new_list_length, char portion2, char *portion3, int new_sock);
void id_operator_server(Customer *list, int new_list_length, char portion2, char *portion3, int new_sock);
void phone_operator_server(Customer *list, int new_list_length, char portion2, char *portion3, int new_sock);
void debt_operator_server(Customer *list, int new_list_length, char portion2, char *portion3, int new_sock);
void date_operator_server(Customer *list, int new_list_length, char portion2, char *portion3, int new_sock);

#endif