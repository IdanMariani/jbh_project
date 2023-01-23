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