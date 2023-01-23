#include "read_csv.h"

void find_max_lines(FILE *file, int *max_lines)
{
    char c;

    do
    {
        c = fgetc(file);

        if (c == '\n')
        {
            *max_lines += 1;
        }

    } while (c != EOF);

    fseek(file, 0, SEEK_SET);
}
