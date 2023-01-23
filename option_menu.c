#include "option_menu.h"

bool found_in_list(Customer *list, int new_list_length, char *portion3, int index)
{
    float f_portion = atof(portion3);

    for (int i = 0; i < new_list_length; i++)
    {
        switch (index)
        {
        case 0:
            if (strcmp(list[i].first_name, portion3) == 0)
            {
                return true;
            }
            break;
        case 1:
            if (strcmp(list[i].last_name, portion3) == 0)
            {
                return true;
            }
            break;
        case 2:
            if (strcmp(list[i].id, portion3) == 0)
            {
                return true;
            }
            break;
        case 3:
            if (strcmp(list[i].phone, portion3) == 0)
            {
                return true;
            }
            break;
        case 4:
            if (list[i].debt == f_portion)
            {
                return true;
            }
            break;
        case 5:
            if (strcmp(list[i].date, portion3) == 0)
            {
                return true;
            }
            break;

        default:
            break;
        }
    }

    return false;
}

void select_option_menu(Customer *list, int *new_list_length, char *buffer, char portion2, char *portion3)
{
    char *select_menu[] = {"select first name", "select last name", "select id", "select phone", "select debt", "select date"};

    bool customer_in_list = true;

    for (int i = 0; i < ARR_SIZE(select_menu); i++)
    {
        if (strstr(buffer, select_menu[i]))
        {
            customer_in_list = found_in_list(list, *new_list_length, portion3, i);
            if (customer_in_list == true)
            {
                print_operator(list, *new_list_length, i, portion2, portion3);
                break;
            }
            else if (customer_in_list == false)
            {
                printf("%s was not found in list\n", portion3);
                break;
            }
        }
    }
}
