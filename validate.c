#include "validate.h"

bool is_letter(char c)
{
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool is_number(char c)
{
    if (c >= 48 && c <= 57)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool validate_name(char *name)
{
    int length = strlen(name);

    if (length > 15)
    {
        printf("error first name is bigger then 15 chr.\n");
    }

    for (int i = 0; i < length; i++)
    {
        if (!is_letter(name[i]))
        {
            printf("Error reading name - need only characters.\n");
            return false;
        }
    }
    return true;
}

bool validate_lastname(char *lastname)
{
    int length = strlen(lastname);

    if (length > 20)
    {
        printf("error first name is bigger then 20 chr.\n");
    }

    for (int i = 0; i < length; i++)
    {
        if (!is_letter(lastname[i]))
        {
            printf("Error reading last name - need only characters.\n");
            return false;
        }
    }
    return true;
}

bool validate_id(char *id)
{
    int length = strlen(id);

    if ((length != 9))
    {
        printf("Error reading id - need min of 9 characters.\n");
        return false;
    }

    for (int i = 0; i < length; i++)
    {
        if (!is_number(id[i]))
        {
            printf("Error reading id - need only numbers.\n");
            return false;
        }
    }
    return true;
}

bool validate_phone_number(char *number)
{
    int length = strlen(number);

    if (length != 10)
    {
        printf("Error reading phone number - need min of 10 numbers.\n");
        return false;
    }

    if (!(number[0] == 48))
    {
        printf("Error reading phone number - first number need to start at 0.\n");
        return false;
    }

    for (int i = 0; i < length; i++)
    {
        if (!is_number(number[i]))
        {
            printf("Error reading phone number - need only numbers.\n");
            return false;
        }
    }
    return true;
}

bool validate_debt(char *number)
{
    int length = strlen(number);

    if (number[0] == '-')
    {
        for (int i = 1; i < length; i++)
        {
            if (!(number[i] >= 48 && number[i] <= 57))
            {
                printf("Error reading debt - need only numbers.");
                return false;
            }
        }
    }

    else
    {
        for (int i = 0; i < length; i++)
        {
            if (!(number[i] >= 48 && number[i] <= 57))
            {
                printf("Error reading debt - need only numbers.");
                return false;
            }
        }
    }

    return true;
}

bool validate_date(char *date)
{
    int length = strlen(date);
    bool has_backslash = false;

    if (length < 10)
    {
        printf("Error reading date - need 10 characters in format dd/mm/yyyy.\n");
        return false;
    }

    if (length > 10)
    {
        printf("Error reading date - need 10 characters in format dd/mm/yyyy.\n");
        return false;
    }

    for (int i = 0; i < length; i++)
    {
        if (date[i] == '/')
        {
            has_backslash = true;
        }
    }

    if (has_backslash == false)
    {
        printf("Error reading date - need / in format.\n");
    }

    int day = 0;
    int month = 0;
    int year = 0;
    char day_c[2] = {0};
    char month_c[2] = {0};
    char year_c[4] = {0};

    strncpy(day_c, date, 2);
    day = atoi(day_c);
    date = strstr(date, "/");
    date++;
    strncpy(month_c, date, 2);
    month = atoi(month_c);
    date = strstr(date, "/");
    date++;
    strncpy(year_c, date, 4);
    year = atoi(year_c);

    if (!(day > 0 && day < 32))
    {
        printf("Error reading day in date.\n");
        return false;
    }

    if (!(month > 0 && month < 13))
    {
        printf("Error reading month in date.\n");
        return false;
    }

    if (!(year > 1900 && year < 2024))
    {
        printf("Error reading year in date - min year is 1900.\n");
        return false;
    }

    return true;
}

bool check_all_validation(Customer *customer)
{
    if (!validate_name(customer->first_name))
    {
        return false;
    }
    if (!validate_lastname(customer->last_name))
    {
        return false;
    }
    if (!validate_id(customer->id))
    {
        return false;
    }
    if (!validate_phone_number(customer->phone))
    {
        return false;
    }
    if (!validate_date(customer->date))
    {
        return false;
    }
    return true;
}







