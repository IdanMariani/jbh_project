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

int read_from_csv_file(FILE *file, Customer *customers)
{
    int read = 0;
    int records = 0;

    do
    {
        read = fscanf(file, "%29[^,],%29[^,],%9[^,],%10[^,],%f,%11s\n", customers[records].first_name,
                      customers[records].last_name, customers[records].id,
                      customers[records].phone, &customers[records].debt, customers[records].date);

        if (read != 6 && !feof(file))
        {
            printf("File format incorrect.\n");
            return 0;
        }

        if (!check_all_validation(&customers[records]))
        {
            return 0;
        }

        if (read == 6)
        {
            records++;
        }

        if (ferror(file))
        {
            printf("Error reading file.\n");
            return 0;
        }
    } while (!feof(file));

    fclose(file);

    return 1;
}