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














