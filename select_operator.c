#include "select_operator.h"

bool fill_portion2_operator(int index, char *portion2)
{
    switch (index)
    {
    case 0:
        *portion2 = '!';
        return true;
        break;
    case 1:
        *portion2 = '=';
        return true;
        break;
    case 2:
        *portion2 = '<';
        return true;
        break;
    case 3:
        *portion2 = '>';
        return true;
        break;
    default:
        break;
    }

    return false;
}

void print_operator(Customer *list, int new_list_length, int index, char portion2, char *portion3)
{
    switch (index)
    {
    case 0:
        first_name_operator(list, new_list_length, portion2, portion3);
        break;
    case 1:
        last_name_operator(list, new_list_length, portion2, portion3);
        break;
    case 2:
        id_operator(list, new_list_length, portion2, portion3);
        break;
    case 3:
        phone_operator(list, new_list_length, portion2, portion3);
        break;
    case 4:
        debt_operator(list, new_list_length, portion2, portion3);
        break;
    case 5:
        date_operator(list, new_list_length, portion2, portion3);
        break;
    default:
        break;
    }
}