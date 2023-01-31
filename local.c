#include "general.h"
#include "read_csv.h"
#include "validate.h"
#include "select_operator.h"
#include "option_menu.h"

void all_input_logic(Customer *list, int new_list_length, bool *has_quit)
{
    char buffer[MAX_BUFFER] = {0};
    char temp_buffer[MAX_BUFFER] = {0};

    char *select_menu[] = {"select first name", "select last name", "select id", "select phone", "select debt", "select date"};
    char *operator_menu[] = {"!=", "=", "<", ">"};
    char select_dilimiter[] = "=<>";
    char operator_delimiter[] = "-abcdefghijklmnopqrstuvwxyz0123456789";

    bool set_flag = false;
    enum Compiler comp = COMP_LOCAL;

    while (1)
    {
        // we get input buffer from user
        fgets(buffer, MAX_BUFFER, stdin);
        strcpy(temp_buffer, buffer);
        int buffer_length = strlen(buffer);
        buffer[buffer_length - 1] = '\0';

        // turn all input to lower case
        switch_to_lower(buffer);
        printf("\n");

        // if user enter "set" on input we go for diffrent section with diffrent validation tests
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
            print_list(list, new_list_length, comp);
            goto end;
        }

        // we start checking first catgory
        char *portion1 = strtok(buffer, select_dilimiter);

        if (portion1 == NULL)
        {
            printf("Error first args\n");
            goto end;
        }

        char *portion3 = strtok(NULL, "\0");
        char *remove_char = strtok(portion1, "!");

        bool select_check_counter = false;
        int select_args = 0;
        for (int i = 0; i < ARR_SIZE(select_menu); i++)
        {
            if (strcmp(portion1, select_menu[i]) == 0)
            {
                select_check_counter = true;
                select_args = i;
                bool error_spaces = spaces_count(portion1, select_args);
                if (error_spaces)
                {
                    printf("Error first args\n");
                    goto end;
                }
            }
        }

        if (select_check_counter == false)
        {
            printf("Error first args.\n");
            goto end;
        }

        // we start checking second catgory (operator)
        bool select_portion2_counter = false;
        char *check_portion2_cut = NULL;
        char portion2 = '\0';
        bool compere_valid = false;
        for (int i = 0; i < ARR_SIZE(operator_menu); i++)
        {
            if ((check_portion2_cut = strstr(temp_buffer, operator_menu[i])))
            {
                select_portion2_counter = true;
                check_portion2_cut = strtok(check_portion2_cut, operator_delimiter);
                for (int i = 0; i < ARR_SIZE(operator_menu); i++)
                {
                    if (strcmp(check_portion2_cut, operator_menu[i]) == 0)
                    {
                        compere_valid = fill_portion2_operator(i, &portion2);
                        if (compere_valid)
                        {
                            break;
                        }
                    }
                }

                if (compere_valid == true)
                {
                    break;
                }
            }
        }

        // finally we check last catagory
        if (select_portion2_counter == true && portion3 == NULL)
        {
            printf("Error third args.\n");
            goto end;
        }

        if (select_portion2_counter == false || compere_valid == false)
        {
            printf("Error second args.\n");
            goto end;
        }

        if (!check_all_validation_select(portion3, select_args))
        {
            goto end;
        }

        // if we pass all 3 catgory valid input of select option we call select option function
        select_option_menu(list, &new_list_length, buffer, portion2, portion3, comp);

    // set menu will only enter if set_flag is true
    set_option:
        if (set_flag == true)
        {
            bool error_file_open = false;
            list = set_option_menu(list, &new_list_length, buffer, &error_file_open,comp);
            if (error_file_open)
            {
                return;
            }
            set_flag = false;
        }

    end:
        // we go to end if error happend during input user or if user enter print
        printf("\n");
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
    print_list(list, new_list_length, comp);

    bool has_quit = false;
    all_input_logic(list, new_list_length, &has_quit);

    return 0;
}
