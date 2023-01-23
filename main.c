#include "general.h"
#include "read_csv.h"
#include "validate.h"

int main(int argc, char *argv[])
{
    Customer *customers;
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

    int max_lines = 1;
    find_max_lines(file, &max_lines);
    customers = malloc(sizeof(Customer) * max_lines);

    fclose(file);

    return 0;
}