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

bool find_highest_date(char *date1, char *date2)
{
    char date1_arr[11];
    char date2_arr[11];
    strcpy(date1_arr, date1);
    strcpy(date2_arr, date2);

    char *d1 = strtok(date1_arr, "/");
    char *m1 = strtok(NULL, "/");
    char *y1 = strtok(NULL, "\0");

    char *d2 = strtok(date2_arr, "/");
    char *m2 = strtok(NULL, "/");
    char *y2 = strtok(NULL, "\0");

    if (strcmp(y1, y2) < 0)
    {
        return true;
    }
    if (strcmp(y1, y2) == 0)
    {
        if (strcmp(m1, m2) < 0)
        {
            return true;
        }
    }
    if (strcmp(y1, y2) == 0)
    {
        if (strcmp(m1, m2) == 0)
        {
            if (strcmp(d1, d2) < 0)
            {
                return true;
            }
        }
    }

    return false;
}

Customer *count_debt_and_init_array(Customer *customers, int length, int *new_list_length)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char highest_so_far[11];
    char phone[11];
    int new_size = 0;
    Customer *new_arr = malloc(sizeof(Customer));
    if (new_arr == NULL)
    {
        printf("Error malloc new_arr\n");
        return NULL;
    }

    for (i = 0; i < length; i++)
    {
        float total_debt = customers[i].debt;
        strcpy(highest_so_far, customers[i].date);
        strcpy(phone, customers[i].phone);
        int leftFlag = 0;
        for (j = 0; j < i; j++) // LEFT PART
        {
            if (strcmp(customers[j].id, customers[i].id) == 0)
            {
                leftFlag = 1;
                break;
            }
        }
        if (leftFlag == 1) // IF FOUND ON LEFT SIDE
        {
            continue;
        }
        for (j = i + 1; j < length; j++) // RIGHT PART
        {
            if (strcmp(customers[j].id, customers[i].id) == 0)
            {
                total_debt += customers[j].debt;
                strcpy(phone, customers[j].phone);
                if (find_highest_date(highest_so_far, customers[j].date))
                {
                    strcpy(highest_so_far, customers[j].date);
                }
            }
        }
        new_size++;
        new_arr = realloc(new_arr, sizeof(Customer) * new_size);
        for (k; k < new_size; k++)
        {
            strcpy(new_arr[k].first_name, customers[i].first_name);
            strcpy(new_arr[k].last_name, customers[i].last_name);
            strcpy(new_arr[k].id, customers[i].id);
            strcpy(new_arr[k].phone, phone);
            new_arr[k].debt = total_debt;
            strcpy(new_arr[k].date, highest_so_far);
        }
    }

    *new_list_length = new_size;

    if (new_arr == NULL)
    {
        printf("new arr is NULL\n");
        return NULL;
    }

    return new_arr;
}

