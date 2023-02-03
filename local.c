#include "general.h"
#include "read_csv.h"
#include "validate.h"
#include "select_operator.h"
#include "option_menu.h"
#include "user_input.h"

void all_input_logic(Customer *list, int new_list_length, bool *has_quit)
{
    enum Compiler comp = COMP_LOCAL;
    char buffer[MAX_BUFFER] = {0};

    char portion2 = '\0';
    char portion3[MAX_BUFFER] = {0};

    bool error_input = false;
    bool set_flag = false;

    while (1)
    {
        fgets(buffer, MAX_BUFFER, stdin);
        int buffer_length = strlen(buffer);
        buffer[buffer_length - 1] = '\0';
        switch_to_lower(buffer);
        printf("\n");

        if (strstr(buffer, "set"))
        {
            set_flag = true;
            goto set_option;
        }

        if (strcmp(buffer, "quit") == 0)
        {
            *has_quit = true;
            free(list);
            return;
        }

        if (strcmp(buffer, "print") == 0)
        {
            print_list_new(list, new_list_length, cb_print_local);
            goto end;
        }

        error_handle(buffer, &portion2, portion3, &error_input, comp);
        if (error_input == true)
        {
            goto end;
        }

        select_option_menu(list, &new_list_length, buffer, portion2, portion3, comp);

    set_option:
        if (set_flag == true)
        {
            bool error_file_open = false;
            list = set_option_menu(list, &new_list_length, buffer, &error_file_open, comp);
            if (error_file_open)
            {
                return;
            }
            set_flag = false;
        }

    end:
        error_input = false;
        puts("");
    }
}

int main(int argc, char *argv[])
{
    Customer *customers, *list;
    FILE *file;
    enum Compiler comp = COMP_LOCAL;

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
    print_list_new(list, new_list_length, cb_print_local);

    bool has_quit = false;
    all_input_logic(list, new_list_length, &has_quit);

    return 0;
}
