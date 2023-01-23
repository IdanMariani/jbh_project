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

void first_name_operator(Customer *list, int new_list_length, char portion2, char *portion3)
{
    switch (portion2)
    {
    case '!':
        printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        for (int i = 0; i < 85; i++)
        {
            printf("*");
        }
        printf("\n");
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].first_name, portion3) == 0)
            {
                continue;
            }
            else
            {
                printf("%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                       list[i].id, list[i].phone, list[i].debt, list[i].date);
            }
        }
        printf("\n");
        break;
    case '=':
        printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        for (int i = 0; i < 85; i++)
        {
            printf("*");
        }
        printf("\n");
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].first_name, portion3) == 0)
            {
                printf("%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                       list[i].id, list[i].phone, list[i].debt, list[i].date);
            }
        }
        printf("\n");
        break;
    case '<':
        printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        for (int i = 0; i < 85; i++)
        {
            printf("*");
        }
        printf("\n");
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].first_name, portion3) < 0)
            {
                printf("%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                       list[i].id, list[i].phone, list[i].debt, list[i].date);
            }
        }
        printf("\n");
        break;
    case '>':
        printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        for (int i = 0; i < 85; i++)
        {
            printf("*");
        }
        printf("\n");
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].first_name, portion3) > 0)
            {
                printf("%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                       list[i].id, list[i].phone, list[i].debt, list[i].date);
            }
        }
        printf("\n");
        break;
    default:
        break;
    }
}

void last_name_operator(Customer *list, int new_list_length, char portion2, char *portion3)
{
    switch (portion2)
    {
    case '!':
        printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        for (int i = 0; i < 85; i++)
        {
            printf("*");
        }
        printf("\n");
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].last_name, portion3) == 0)
            {
                continue;
            }
            else
            {
                printf("%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                       list[i].id, list[i].phone, list[i].debt, list[i].date);
            }
        }
        printf("\n");
        break;
    case '=':
        printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        for (int i = 0; i < 85; i++)
        {
            printf("*");
        }
        printf("\n");
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].last_name, portion3) == 0)
            {
                printf("%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                       list[i].id, list[i].phone, list[i].debt, list[i].date);
            }
        }
        printf("\n");
        break;
    case '<':
        printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        for (int i = 0; i < 85; i++)
        {
            printf("*");
        }
        printf("\n");
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].last_name, portion3) < 0)
            {
                printf("%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                       list[i].id, list[i].phone, list[i].debt, list[i].date);
            }
        }
        printf("\n");
        break;
    case '>':
        printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        for (int i = 0; i < 85; i++)
        {
            printf("*");
        }
        printf("\n");
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].last_name, portion3) > 0)
            {
                printf("%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                       list[i].id, list[i].phone, list[i].debt, list[i].date);
            }
        }
        printf("\n");
        break;
    default:
        break;
    }
}

void id_operator(Customer *list, int new_list_length, char portion2, char *portion3)
{
    switch (portion2)
    {
    case '!':
        printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        for (int i = 0; i < 85; i++)
        {
            printf("*");
        }
        printf("\n");
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].id, portion3) == 0)
            {
                continue;
            }
            else
            {
                printf("%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                       list[i].id, list[i].phone, list[i].debt, list[i].date);
            }
        }
        printf("\n");
        break;
    case '=':
        printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        for (int i = 0; i < 85; i++)
        {
            printf("*");
        }
        printf("\n");
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].id, portion3) == 0)
            {
                printf("%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                       list[i].id, list[i].phone, list[i].debt, list[i].date);
            }
        }
        printf("\n");
        break;
    case '<':
        printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        for (int i = 0; i < 85; i++)
        {
            printf("*");
        }
        printf("\n");
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].id, portion3) < 0)
            {
                printf("%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                       list[i].id, list[i].phone, list[i].debt, list[i].date);
            }
        }
        printf("\n");
        break;
    case '>':
        printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        for (int i = 0; i < 85; i++)
        {
            printf("*");
        }
        printf("\n");
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].id, portion3) > 0)
            {
                printf("%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                       list[i].id, list[i].phone, list[i].debt, list[i].date);
            }
        }
        printf("\n");
        break;
    default:
        break;
    }
}

void phone_operator(Customer *list, int new_list_length, char portion2, char *portion3)
{
    switch (portion2)
    {
    case '!':
        printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        for (int i = 0; i < 85; i++)
        {
            printf("*");
        }
        printf("\n");
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].phone, portion3) == 0)
            {
                continue;
            }
            else
            {
                printf("%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                       list[i].id, list[i].phone, list[i].debt, list[i].date);
            }
        }
        printf("\n");
        break;
    case '=':
        printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        for (int i = 0; i < 85; i++)
        {
            printf("*");
        }
        printf("\n");
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].phone, portion3) == 0)
            {
                printf("%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                       list[i].id, list[i].phone, list[i].debt, list[i].date);
            }
        }
        printf("\n");
        break;
    case '<':
        printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        for (int i = 0; i < 85; i++)
        {
            printf("*");
        }
        printf("\n");
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].phone, portion3) < 0)
            {
                printf("%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                       list[i].id, list[i].phone, list[i].debt, list[i].date);
            }
        }
        printf("\n");
        break;
    case '>':
        printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        for (int i = 0; i < 85; i++)
        {
            printf("*");
        }
        printf("\n");
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].phone, portion3) > 0)
            {
                printf("%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                       list[i].id, list[i].phone, list[i].debt, list[i].date);
            }
        }
        printf("\n");
        break;
    default:
        break;
    }
}

void debt_operator(Customer *list, int new_list_length, char portion2, char *portion3)
{

    float f_portion3 = atof(portion3);

    switch (portion2)
    {
    case '!':
        printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        for (int i = 0; i < 85; i++)
        {
            printf("*");
        }
        printf("\n");
        for (int i = 0; i < new_list_length; i++)
        {
            if (list[i].debt == f_portion3)
            {
                continue;
            }
            else
            {
                printf("%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                       list[i].id, list[i].phone, list[i].debt, list[i].date);
            }
        }
        printf("\n");
        break;
    case '=':
        printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        for (int i = 0; i < 85; i++)
        {
            printf("*");
        }
        printf("\n");
        for (int i = 0; i < new_list_length; i++)
        {
            if (list[i].debt == f_portion3)
            {
                printf("%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                       list[i].id, list[i].phone, list[i].debt, list[i].date);
            }
        }
        printf("\n");
        break;
    case '<':
        printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        for (int i = 0; i < 85; i++)
        {
            printf("*");
        }
        printf("\n");
        for (int i = 0; i < new_list_length; i++)
        {
            if (list[i].debt > f_portion3)
            {
                printf("%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                       list[i].id, list[i].phone, list[i].debt, list[i].date);
            }
        }
        printf("\n");
        break;
    case '>':
        printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        for (int i = 0; i < 85; i++)
        {
            printf("*");
        }
        printf("\n");
        for (int i = 0; i < new_list_length; i++)
        {
            if (list[i].debt < f_portion3)
            {
                printf("%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                       list[i].id, list[i].phone, list[i].debt, list[i].date);
            }
        }
        printf("\n");
        break;
    default:
        break;
    }
}
