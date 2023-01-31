#include "user_input.h"

void error_handle(char *buffer, char *portion2, char *portion3, bool *error_input, enum Compiler comp)
{
    char *select_menu[] = {"select first name", "select last name", "select id", "select phone", "select debt", "select date"};
    char select_dilimiter[] = "=<>";
    char operator_delimiter[] = "-abcdefghijklmnopqrstuvwxyz0123456789";
    char *operator_menu[] = {"!=", "=", "<", ">"};

    char new_buffer[MAX_BUFFER] = {0};
    char temp_buffer[MAX_BUFFER] = {0};

    strcpy(new_buffer, buffer);
    strcpy(temp_buffer, new_buffer);

    char *portion1 = strtok(new_buffer, select_dilimiter);

    if (portion1 == NULL)
    {
        *error_input = true;
        if (comp == COMP_LOCAL)
        {
            printf("Error first args\n");
        }
        else if (comp == COMP_SERVER)
        {
            strcpy(buffer_send, "Error first args");
            n = send(new_sock, buffer_send, strlen(buffer_send), 0);
            if (n < 0)
            {
                perror("Server error sending data");
                return;
            }
        }
        return;
    }

    char *portion3_value = strtok(NULL, "\0");
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
                *error_input = true;
                if (comp == COMP_LOCAL)
                {
                    printf("Error first args\n");
                }
                else if (comp == COMP_SERVER)
                {
                    strcpy(buffer_send, "Error first args");
                    n = send(new_sock, buffer_send, strlen(buffer_send), 0);
                    if (n < 0)
                    {
                        perror("Server error sending data");
                        return;
                    }
                }
                return;
            }
        }
    }

    if (select_check_counter == false)
    {
        *error_input = true;
        if (comp == COMP_LOCAL)
        {
            printf("Error first args\n");
        }
        else if (comp == COMP_SERVER)
        {
            strcpy(buffer_send, "Error first args");
            n = send(new_sock, buffer_send, strlen(buffer_send), 0);
            if (n < 0)
            {
                perror("Server error sending data");
                return;
            }
        }
        return;
    }

    // we start checking second catgory (operator)
    bool select_portion2_counter = false;
    char *check_portion2_cut = NULL;
    *portion2 = '\0';
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
                    compere_valid = fill_portion2_operator(i, portion2);
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
    if (select_portion2_counter == true && portion3_value == NULL)
    {
        printf("Error third args.\n");
        *error_input = true;
        return;
    }

    if (select_portion2_counter == false || compere_valid == false)
    {
        *error_input = true;
        if (comp == COMP_LOCAL)
        {
            printf("Error second args\n");
        }
        else if (comp == COMP_SERVER)
        {
            strcpy(buffer_send, "Error second args");
            n = send(new_sock, buffer_send, strlen(buffer_send), 0);
            if (n < 0)
            {
                perror("Server error sending data");
                return;
            }
        }
        return;
    }

    if (!check_all_validation_select(portion3_value, select_args))
    {
        *error_input = true;
        if (comp == COMP_LOCAL)
        {
            printf("error at validation\n");
        }
        else if (comp == COMP_SERVER)
        {
            strcpy(buffer_send, "error at validation\n");
            n = send(new_sock, buffer_send, strlen(buffer_send), 0);
            if (n < 0)
            {
                perror("Server error sending data");
                return;
            }
        }
        return;
    }

    strcpy(portion3, portion3_value);
}

void all_input_logic(Customer *list, int new_list_length, bool *has_quit)
{
    enum Compiler comp = COMP_LOCAL;
    char buffer[MAX_BUFFER] = {0};

    char portion2;
    char portion3[MAX_BUFFER];

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
            print_list(list, new_list_length, comp);
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
        printf("\n");
    }
}