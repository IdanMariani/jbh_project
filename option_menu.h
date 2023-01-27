#ifndef OPTION_MENU_H
#define OPTION_MENU_H

#include "general.h"
#include "select_operator.h"
#include "validate.h"
#include "server.h"

bool found_in_list(Customer *list, int new_list_length, char *portion3, int index);
void select_option_menu(Customer *list, int *new_list_length, char *buffer, char portion2, char *portion3);
Customer *set_option_menu(Customer *list, int *new_list_length, char *buffer, bool *error_file_open);
void select_option_menu_server(Customer *list, int *new_list_length, char *buffer, char portion2, char *portion3);


#endif
