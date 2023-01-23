#include "general.h"
#include "read_csv.h"
#include "validate.h"
#include "select_operator.h"

int main(int argc, char *argv[])
{
    Customer *customers, *list;
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

    // 0 mean we have an error reading the csv file /so we return 1 to stop
    if (read_from_csv_file(file, customers) == 0)
    {
        return 1;
    }

    // create new list array from csv
    int new_list_length = 0;
    list = count_debt_and_init_array(customers, max_lines, &new_list_length);
    if (list == NULL)
    {
        return 1;
    }

    // free old list from csv
    free(customers);

    // show main menu selection only once at start of the program
    bool prompt_menu_for_first_time = true;
    prompt_menu(&prompt_menu_for_first_time);

    sort_list(list, new_list_length);
    print_list(list, new_list_length);

    return 0;
}