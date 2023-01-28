#include "option_menu.h"

bool found_in_list(Customer *list, int new_list_length, char *portion3, int index)
{
    float f_portion = atof(portion3);

    for (int i = 0; i < new_list_length; i++)
    {
        switch (index)
        {
        case 0:
            if (strcmp(list[i].first_name, portion3) == 0)
            {
                return true;
            }
            break;
        case 1:
            if (strcmp(list[i].last_name, portion3) == 0)
            {
                return true;
            }
            break;
        case 2:
            if (strcmp(list[i].id, portion3) == 0)
            {
                return true;
            }
            break;
        case 3:
            if (strcmp(list[i].phone, portion3) == 0)
            {
                return true;
            }
            break;
        case 4:
            if (list[i].debt == f_portion)
            {
                return true;
            }
            break;
        case 5:
            if (strcmp(list[i].date, portion3) == 0)
            {
                return true;
            }
            break;

        default:
            break;
        }
    }

    return false;
}

void select_option_menu(Customer *list, int *new_list_length, char *buffer, char portion2, char *portion3)
{
    char *select_menu[] = {"select first name", "select last name", "select id", "select phone", "select debt", "select date"};

    bool customer_in_list = true;

    for (int i = 0; i < ARR_SIZE(select_menu); i++)
    {
        if (strstr(buffer, select_menu[i]))
        {
            customer_in_list = found_in_list(list, *new_list_length, portion3, i);
            if (customer_in_list == true)
            {
                print_operator(list, *new_list_length, i, portion2, portion3);
                break;
            }
            else if (customer_in_list == false)
            {
                printf("%s was not found in list\n", portion3);
                break;
            }
        }
    }
}

Customer *set_option_menu(Customer *list, int *new_list_length, char *buffer, bool *error_file_open)
{
    char *set_menu[] = {"first name=", "last name=", "id=", "phone=", "debt=", "date="};
    char set_dilimiter[] = "=,";

    int set_check_counter = 0;

    for (int i = 0; i < ARR_SIZE(set_menu); i++)
    {
        if (strstr(buffer, set_menu[i]))
        {
            set_check_counter++;
        }
        else
        {
            char print_clean[11] = {0};
            strcpy(print_clean, set_menu[i]);
            int length = strlen(print_clean);
            print_clean[length - 1] = '\0';
            printf("error at %s", print_clean);
            goto end;
        }
    }

    if (set_check_counter == 6)
    {
        bool null_flag = false;
        char *p_first_name_cut = strtok(buffer, set_dilimiter);
        if (p_first_name_cut == NULL)
            null_flag = true;
        char *p_first_name = strtok(NULL, set_dilimiter);
        if (p_first_name == NULL)
            null_flag = true;
        char *p_l_name_cut = strtok(NULL, set_dilimiter);
        if (p_l_name_cut == NULL)
            null_flag = true;
        char *p_l_name = strtok(NULL, set_dilimiter);
        if (p_l_name == NULL)
            null_flag = true;
        char *p_id_cut = strtok(NULL, set_dilimiter);
        if (p_id_cut == NULL)
            null_flag = true;
        char *p_id = strtok(NULL, set_dilimiter);
        if (p_id == NULL)
            null_flag = true;
        char *p_phone_cut = strtok(NULL, set_dilimiter);
        if (p_phone_cut == NULL)
            null_flag = true;
        char *p_phone = strtok(NULL, set_dilimiter);
        if (p_phone == NULL)
            null_flag = true;
        char *p_debt_cut = strtok(NULL, set_dilimiter);
        if (p_debt_cut == NULL)
            null_flag = true;
        char *p_debt = strtok(NULL, set_dilimiter);
        if (p_debt == NULL)
            null_flag = true;
        char *p_date_cut = strtok(NULL, set_dilimiter);
        if (p_date_cut == NULL)
            null_flag = true;
        char *p_date = strtok(NULL, set_dilimiter);
        if (p_date == NULL)
            null_flag = true;

        if (null_flag == true)
        {
            printf("empty args in set option");
            goto end;
        }

        // we check if user enter more then 6 args to set input
        char *check_overflow = strtok(NULL, set_dilimiter);
        if (check_overflow != NULL)
        {
            printf("Error more then 6 args in set option");
            goto end;
        }

        FILE *file = fopen("customers.txt", "a");
        if (file == NULL)
        {
            printf("Error opening file.\n");
            *error_file_open = true;
            goto end;
        }

        // create a customer and fill details
        Customer *customer = malloc(sizeof(Customer));
        strcpy(customer->first_name, p_first_name);
        strcpy(customer->last_name, p_l_name);
        strcpy(customer->id, p_id);
        strcpy(customer->phone, p_phone);
        customer->debt = atof(p_debt);
        strcpy(customer->date, p_date);

        // 0 mean we have error at validate
        if (validate_debt(p_debt) == 0)
        {
            free(customer);
            goto end;
        }

        // 0 mean we have error at validate
        if (check_all_validation(customer) == 0)
        {
            free(customer);
            goto end;
        }

        // check if customer allready exist in our list if exist.
        // we check for same id with differnt names
        // if same name and id we update debt
        // if same id with diffrent name we print error and we dont update the debt
        int i;
        for (i = 0; i < *new_list_length; i++)
        {
            if (strcmp(list[i].id, customer->id) == 0)
            {
                if (((strcmp(list[i].first_name, customer->first_name) == 0) && strcmp(list[i].last_name, customer->last_name) == 0))
                {
                    list[i].debt += customer->debt;
                    strcpy(list[i].date, customer->date);
                    sort_list(list, *new_list_length);
                    break;
                }
                else
                {
                    printf("customer with same id but has diffrent name");
                    free(customer);
                    goto end;
                }
            }
        }

        // we enter this statment if customer is completly new and we add him to the list
        if (i == *new_list_length)
        {
            *new_list_length += 1;
            list = realloc(list, sizeof(Customer) * *new_list_length);
            list[*new_list_length - 1] = *customer;
            sort_list(list, *new_list_length);
        }

        // we write all details to file
        fprintf(file, "\n%s,%s,%s,%s,%s,%s", p_first_name, p_l_name, p_id, p_phone, p_debt, p_date);
        fclose(file);
        free(customer);
    }
end:
    // we go to end if error happend during input user
    printf("\n");
    return list;
}

void select_option_menu_server(Customer *list, int *new_list_length, char *buffer, char portion2, char *portion3)
{
    char *select_menu[] = {"select first name", "select last name", "select id", "select phone", "select debt", "select date"};
   
    bool customer_in_list = true;

    for (int i = 0; i < ARR_SIZE(select_menu); i++)
    {
        if (strstr(buffer, select_menu[i]))
        {
            customer_in_list = found_in_list(list, *new_list_length, portion3, i);
            if (customer_in_list == true)
            {
                print_operator_server(list, *new_list_length, i, portion2, portion3);
                break;
            }
            else if (customer_in_list == false)
            {
                //printf("%s was not found in list\n", portion3);
                sprintf(buffer_send,"%s was not found in list", portion3);
                break;
            }
        }
    }
}
