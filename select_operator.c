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
