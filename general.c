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






























