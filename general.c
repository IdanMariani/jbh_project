#include "general.h"

void prompt_menu(bool *first_time)
{
    printf("\n");
    if (*first_time == true)
    {
        printf("%45s\n", "|Choose Options|");
        for (int i = 0; i < 85; i++)
        {
            printf("-");
        }
        printf("\n");
        printf("%15s%15s%15s%15s\n", "|Select|", "|Set|", "|Print|", "|Quit|");
        for (int i = 0; i < 85; i++)
        {
            printf("-");
        }
        printf("\n");
        printf("Example For Select Menu: select first name=moshe OR select debt>-200 OR select date=10/12/2000\n\n");
        printf("Example For Set Menu: set first name=avi,last name=cohen,id=212366758,phone=0549987615,debt=-200,date=07/06/2016\n\n");
        printf("Example For Print: print\n\n");
        printf("Example For Print: quit\n\n");
    }
    *first_time = false;
}

void sort_list(Customer *customers, int length)
{
    bool swapped;
    for (int i = 0; i < length - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < length - 1 - i; j++)
        {
            if (customers[j].debt < customers[j + 1].debt)
            {
                Customer temp = customers[j];
                customers[j] = customers[j + 1];
                customers[j + 1] = temp;
                swapped = true;
            }
        }
        if (swapped == false)
        {
            break;
        }
    }
}

void print_list(Customer *customers, int length)
{
    printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");

    for (int i = 0; i < 85; i++)
    {
        printf("*");
    }
    printf("\n");

    for (int i = 0; i < length; i++)
    {
        printf("%-15s%-15s%-15s%-15s%-15.2f%-15s\n", customers[i].first_name, customers[i].last_name,
               customers[i].id, customers[i].phone, customers[i].debt, customers[i].date);
    }
    printf("\n");
}

void switch_to_lower(char *buffer)
{
    int length = strlen(buffer);

    for (int i = 0; i < length; i++)
    {
        if (isupper(buffer[i]))
        {
            buffer[i] = tolower(buffer[i]);
        }
    }
}

bool spaces_count(char *string, int index)
{
    int space_counts = 0;

    int length = strlen(string);

    for (int i = 0; i < length; i++)
    {
        if (string[i] == ' ')
        {
            space_counts++;
        }
    }

    switch (index)
    {
    case 0:
        if (space_counts > 2)
        {
            return true;
        }
        break;
    case 1:
        if (space_counts > 2)
        {
            return true;
        }
        break;
    case 2:

        if (space_counts > 1)
        {
            return true;
        }
        break;
    case 3:

        if (space_counts > 1)
        {
            return true;
        }
        break;
    case 4:
        if (space_counts > 1)
        {
            return true;
        }

        break;
    case 5:
        if (space_counts > 1)
        {
            return true;
        }
        break;
    default:
        break;
    }

    return false;
}






















