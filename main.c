#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *file;

    if (argc != 2)
    {
        printf("Argument number error.\n");
        printf("Enter ./main customers.txt to run program\n");
        return 1;
    }

    file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    fclose(file);

    return 0;
}