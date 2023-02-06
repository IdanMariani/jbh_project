#include "select_operator.h"

bool fill_portion2_operator(int index, char *portion2)
{
    switch (index)
    {
    case 0:
        *portion2 = '!';
        return true;
        break;
    case 1:
        *portion2 = '=';
        return true;
        break;
    case 2:
        *portion2 = '<';
        return true;
        break;
    case 3:
        *portion2 = '>';
        return true;
        break;
    default:
        break;
    }

    return false;
}

void print_operator(Customer *list, int new_list_length, int index, char portion2, char *portion3 ,int comp, int new_sock)
{
    switch (index)
    {
    case 0:
        if (comp == LOCAL)
        {
            first_name_operator(list, new_list_length, portion2, portion3);
        }
        else if (comp == SERVER)
        {
            first_name_operator_server(list, new_list_length, portion2, portion3, new_sock);
        }
        break;
    case 1:
        if (comp == LOCAL)
        {
            last_name_operator(list, new_list_length, portion2, portion3);
        }
        else if (comp == SERVER)
        {
            last_name_operator_server(list, new_list_length, portion2, portion3,new_sock);
        }
        break;
    case 2:
        if (comp == LOCAL)
        {
            id_operator(list, new_list_length, portion2, portion3);
        }
        else if (comp == SERVER)
        {
            id_operator_server(list, new_list_length, portion2, portion3,new_sock);
        }
        break;
    case 3:
        if (comp == LOCAL)
        {
            phone_operator(list, new_list_length, portion2, portion3);
        }
        else if (comp == SERVER)
        {
            phone_operator_server(list, new_list_length, portion2, portion3,new_sock);
        }
        break;
    case 4:
        if (comp == LOCAL)
        {
            debt_operator(list, new_list_length, portion2, portion3);
        }
        else if (comp == SERVER)
        {
            debt_operator_server(list, new_list_length, portion2, portion3,new_sock);
        }
        break;
    case 5:
        if (comp == LOCAL)
        {
            date_operator(list, new_list_length, portion2, portion3);
        }
        else if (comp == SERVER)
        {
            date_operator_server(list, new_list_length, portion2, portion3,new_sock);
        }
        break;
    default:
        break;
    }
}

void first_name_operator(Customer *list, int new_list_length, char portion2, char *portion3)
{
    switch (portion2)
    {
    case '!':
        printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        for (int i = 0; i < 85; i++)
        {
            printf("*");
        }
        printf("\n");
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].first_name, portion3) == 0)
            {
                continue;
            }
            else
            {
                printf("%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                       list[i].id, list[i].phone, list[i].debt, list[i].date);
            }
        }
        printf("\n");
        break;
    case '=':
        printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        for (int i = 0; i < 85; i++)
        {
            printf("*");
        }
        printf("\n");
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].first_name, portion3) == 0)
            {
                printf("%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                       list[i].id, list[i].phone, list[i].debt, list[i].date);
            }
        }
        printf("\n");
        break;
    case '<':
        printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        for (int i = 0; i < 85; i++)
        {
            printf("*");
        }
        printf("\n");
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].first_name, portion3) < 0)
            {
                printf("%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                       list[i].id, list[i].phone, list[i].debt, list[i].date);
            }
        }
        printf("\n");
        break;
    case '>':
        printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        for (int i = 0; i < 85; i++)
        {
            printf("*");
        }
        printf("\n");
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].first_name, portion3) > 0)
            {
                printf("%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                       list[i].id, list[i].phone, list[i].debt, list[i].date);
            }
        }
        printf("\n");
        break;
    default:
        break;
    }
}

void last_name_operator(Customer *list, int new_list_length, char portion2, char *portion3)
{
    switch (portion2)
    {
    case '!':
        printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        for (int i = 0; i < 85; i++)
        {
            printf("*");
        }
        printf("\n");
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].last_name, portion3) == 0)
            {
                continue;
            }
            else
            {
                printf("%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                       list[i].id, list[i].phone, list[i].debt, list[i].date);
            }
        }
        printf("\n");
        break;
    case '=':
        printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        for (int i = 0; i < 85; i++)
        {
            printf("*");
        }
        printf("\n");
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].last_name, portion3) == 0)
            {
                printf("%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                       list[i].id, list[i].phone, list[i].debt, list[i].date);
            }
        }
        printf("\n");
        break;
    case '<':
        printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        for (int i = 0; i < 85; i++)
        {
            printf("*");
        }
        printf("\n");
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].last_name, portion3) < 0)
            {
                printf("%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                       list[i].id, list[i].phone, list[i].debt, list[i].date);
            }
        }
        printf("\n");
        break;
    case '>':
        printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        for (int i = 0; i < 85; i++)
        {
            printf("*");
        }
        printf("\n");
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].last_name, portion3) > 0)
            {
                printf("%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                       list[i].id, list[i].phone, list[i].debt, list[i].date);
            }
        }
        printf("\n");
        break;
    default:
        break;
    }
}

void id_operator(Customer *list, int new_list_length, char portion2, char *portion3)
{
    switch (portion2)
    {
    case '!':
        printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        for (int i = 0; i < 85; i++)
        {
            printf("*");
        }
        printf("\n");
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].id, portion3) == 0)
            {
                continue;
            }
            else
            {
                printf("%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                       list[i].id, list[i].phone, list[i].debt, list[i].date);
            }
        }
        printf("\n");
        break;
    case '=':
        printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        for (int i = 0; i < 85; i++)
        {
            printf("*");
        }
        printf("\n");
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].id, portion3) == 0)
            {
                printf("%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                       list[i].id, list[i].phone, list[i].debt, list[i].date);
            }
        }
        printf("\n");
        break;
    case '<':
        printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        for (int i = 0; i < 85; i++)
        {
            printf("*");
        }
        printf("\n");
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].id, portion3) < 0)
            {
                printf("%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                       list[i].id, list[i].phone, list[i].debt, list[i].date);
            }
        }
        printf("\n");
        break;
    case '>':
        printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        for (int i = 0; i < 85; i++)
        {
            printf("*");
        }
        printf("\n");
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].id, portion3) > 0)
            {
                printf("%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                       list[i].id, list[i].phone, list[i].debt, list[i].date);
            }
        }
        printf("\n");
        break;
    default:
        break;
    }
}

void phone_operator(Customer *list, int new_list_length, char portion2, char *portion3)
{
    switch (portion2)
    {
    case '!':
        printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        for (int i = 0; i < 85; i++)
        {
            printf("*");
        }
        printf("\n");
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].phone, portion3) == 0)
            {
                continue;
            }
            else
            {
                printf("%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                       list[i].id, list[i].phone, list[i].debt, list[i].date);
            }
        }
        printf("\n");
        break;
    case '=':
        printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        for (int i = 0; i < 85; i++)
        {
            printf("*");
        }
        printf("\n");
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].phone, portion3) == 0)
            {
                printf("%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                       list[i].id, list[i].phone, list[i].debt, list[i].date);
            }
        }
        printf("\n");
        break;
    case '<':
        printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        for (int i = 0; i < 85; i++)
        {
            printf("*");
        }
        printf("\n");
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].phone, portion3) < 0)
            {
                printf("%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                       list[i].id, list[i].phone, list[i].debt, list[i].date);
            }
        }
        printf("\n");
        break;
    case '>':
        printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        for (int i = 0; i < 85; i++)
        {
            printf("*");
        }
        printf("\n");
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].phone, portion3) > 0)
            {
                printf("%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                       list[i].id, list[i].phone, list[i].debt, list[i].date);
            }
        }
        printf("\n");
        break;
    default:
        break;
    }
}

void debt_operator(Customer *list, int new_list_length, char portion2, char *portion3)
{

    float f_portion3 = atof(portion3);

    switch (portion2)
    {
    case '!':
        printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        for (int i = 0; i < 85; i++)
        {
            printf("*");
        }
        printf("\n");
        for (int i = 0; i < new_list_length; i++)
        {
            if (list[i].debt == f_portion3)
            {
                continue;
            }
            else
            {
                printf("%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                       list[i].id, list[i].phone, list[i].debt, list[i].date);
            }
        }
        printf("\n");
        break;
    case '=':
        printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        for (int i = 0; i < 85; i++)
        {
            printf("*");
        }
        printf("\n");
        for (int i = 0; i < new_list_length; i++)
        {
            if (list[i].debt == f_portion3)
            {
                printf("%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                       list[i].id, list[i].phone, list[i].debt, list[i].date);
            }
        }
        printf("\n");
        break;
    case '<':
        printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        for (int i = 0; i < 85; i++)
        {
            printf("*");
        }
        printf("\n");
        for (int i = 0; i < new_list_length; i++)
        {
            if (list[i].debt > f_portion3)
            {
                printf("%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                       list[i].id, list[i].phone, list[i].debt, list[i].date);
            }
        }
        printf("\n");
        break;
    case '>':
        printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        for (int i = 0; i < 85; i++)
        {
            printf("*");
        }
        printf("\n");
        for (int i = 0; i < new_list_length; i++)
        {
            if (list[i].debt < f_portion3)
            {
                printf("%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                       list[i].id, list[i].phone, list[i].debt, list[i].date);
            }
        }
        printf("\n");
        break;
    default:
        break;
    }
}

void date_operator(Customer *list, int new_list_length, char portion2, char *portion3)
{
    switch (portion2)
    {
    case '!':
        printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        for (int i = 0; i < 85; i++)
        {
            printf("*");
        }
        printf("\n");
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].date, portion3) == 0)
            {
                continue;
            }
            else
            {
                printf("%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                       list[i].id, list[i].phone, list[i].debt, list[i].date);
            }
        }
        printf("\n");
        break;
    case '=':
        printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        for (int i = 0; i < 85; i++)
        {
            printf("*");
        }
        printf("\n");
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].date, portion3) == 0)
            {
                printf("%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                       list[i].id, list[i].phone, list[i].debt, list[i].date);
            }
        }
        printf("\n");
        break;
    case '<':
        printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        for (int i = 0; i < 85; i++)
        {
            printf("*");
        }
        printf("\n");

        char new_string_smaller[11];
        strcpy(new_string_smaller, portion3);
        char *d1 = strtok(new_string_smaller, "/");
        char *m1 = strtok(NULL, "/");
        char *y1 = strtok(NULL, "/");

        char temp_string_smaller[11];

        for (int i = 0; i < new_list_length; i++)
        {
            strcpy(temp_string_smaller, list[i].date);
            char *d2 = strtok(temp_string_smaller, "/");
            char *m2 = strtok(NULL, "/");
            char *y2 = strtok(NULL, "/");

            if (strcmp(y2, y1) < 0)
            {
                printf("%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                       list[i].id, list[i].phone, list[i].debt, list[i].date);
            }
            if (strcmp(y2, y1) == 0)
            {
                if (strcmp(m2, m1) < 0)
                {
                    printf("%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                           list[i].id, list[i].phone, list[i].debt, list[i].date);
                }
            }
            if (strcmp(y2, y1) == 0)
            {
                if (strcmp(m2, m1) == 0)
                {
                    if (strcmp(d2, d1) < 0)
                    {
                        printf("%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                               list[i].id, list[i].phone, list[i].debt, list[i].date);
                    }
                }
            }
        }
        printf("\n");
        break;
    case '>':
        printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        for (int i = 0; i < 85; i++)
        {
            printf("*");
        }
        printf("\n");

        char new_string_bigger[11];
        strcpy(new_string_bigger, portion3);
        char *d_1 = strtok(new_string_bigger, "/");
        char *m_1 = strtok(NULL, "/");
        char *y_1 = strtok(NULL, "/");

        char temp_string_bigger[11];

        for (int i = 0; i < new_list_length; i++)
        {
            strcpy(temp_string_bigger, list[i].date);
            char *d_2 = strtok(temp_string_bigger, "/");
            char *m_2 = strtok(NULL, "/");
            char *y_2 = strtok(NULL, "/");

            if (strcmp(y_2, y_1) > 0)
            {
                printf("%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                       list[i].id, list[i].phone, list[i].debt, list[i].date);
            }
            if (strcmp(y_2, y_1) == 0)
            {
                if (strcmp(m_2, m_1) > 0)
                {
                    printf("%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                           list[i].id, list[i].phone, list[i].debt, list[i].date);
                }
            }
            if (strcmp(y_2, y_1) == 0)
            {
                if (strcmp(m_2, m_1) == 0)
                {
                    if (strcmp(d_2, d_1) > 0)
                    {
                        printf("%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                               list[i].id, list[i].phone, list[i].debt, list[i].date);
                    }
                }
            }
        }
        printf("\n");
        break;
    default:
        break;
    }
}

void first_name_operator_server(Customer *list, int new_list_length, char portion2, char *portion3, int new_sock)
{
    char buffer_send[MAX_BUFFER];
    int n;
    switch (portion2)
    {
    case '!':
        sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            break;
        }
        sprintf(buffer_send, "%s\n", "*************************************************************************************");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            break;
        }
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].first_name, portion3) == 0)
            {
                continue;
            }
            else
            {
                sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                        list[i].id, list[i].phone, list[i].debt, list[i].date);
                n = send(new_sock, buffer_send, strlen(buffer_send), 0);
                if (n < 0)
                {
                    perror("Server error sending data");
                    break;
                }
            }
        }
        break;
    case '=':
        sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            break;
        }
        sprintf(buffer_send, "%s\n", "*************************************************************************************");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            break;
        }
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].first_name, portion3) == 0)
            {
                sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                        list[i].id, list[i].phone, list[i].debt, list[i].date);
                n = send(new_sock, buffer_send, strlen(buffer_send), 0);
                if (n < 0)
                {
                    perror("Server error sending data");
                    break;
                }
            }
        }
        break;
    case '<':
        sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            break;
        }
        sprintf(buffer_send, "%s\n", "*************************************************************************************");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].first_name, portion3) < 0)
            {
                sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                        list[i].id, list[i].phone, list[i].debt, list[i].date);
                n = send(new_sock, buffer_send, strlen(buffer_send), 0);
                if (n < 0)
                {
                    perror("Server error sending data");
                    break;
                }
            }
        }
        break;
    case '>':
        sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            break;
        }
        sprintf(buffer_send, "%s\n", "*************************************************************************************");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].first_name, portion3) > 0)
            {
                sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                        list[i].id, list[i].phone, list[i].debt, list[i].date);
                n = send(new_sock, buffer_send, strlen(buffer_send), 0);
                if (n < 0)
                {
                    perror("Server error sending data");
                    break;
                }
            }
        }
        break;
    default:
        break;
    }
}

void last_name_operator_server(Customer *list, int new_list_length, char portion2, char *portion3, int new_sock)
{
    char buffer_send[MAX_BUFFER];
    int n;
    switch (portion2)
    {
    case '!':
        sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            break;
        }
        sprintf(buffer_send, "%s\n", "*************************************************************************************");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            break;
        }
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].last_name, portion3) == 0)
            {
                continue;
            }
            else
            {
                sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                        list[i].id, list[i].phone, list[i].debt, list[i].date);
                n = send(new_sock, buffer_send, strlen(buffer_send), 0);
                if (n < 0)
                {
                    perror("Server error sending data");
                    break;
                }
            }
        }
        break;
    case '=':
        sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            break;
        }
        sprintf(buffer_send, "%s\n", "*************************************************************************************");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            break;
        }
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].last_name, portion3) == 0)
            {
                sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                        list[i].id, list[i].phone, list[i].debt, list[i].date);
                n = send(new_sock, buffer_send, strlen(buffer_send), 0);
                if (n < 0)
                {
                    perror("Server error sending data");
                    break;
                }
            }
        }
        break;
    case '<':
        sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            break;
        }
        sprintf(buffer_send, "%s\n", "*************************************************************************************");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            break;
        }
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].last_name, portion3) < 0)
            {
                sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                        list[i].id, list[i].phone, list[i].debt, list[i].date);
                n = send(new_sock, buffer_send, strlen(buffer_send), 0);
                if (n < 0)
                {
                    perror("Server error sending data");
                    break;
                }
            }
        }
        break;
    case '>':
        sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            break;
        }
        sprintf(buffer_send, "%s\n", "*************************************************************************************");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            break;
        }
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].last_name, portion3) > 0)
            {
                sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                        list[i].id, list[i].phone, list[i].debt, list[i].date);
                n = send(new_sock, buffer_send, strlen(buffer_send), 0);
                if (n < 0)
                {
                    perror("Server error sending data");
                    break;
                }
            }
        }
        break;
    default:
        break;
    }
}

void id_operator_server(Customer *list, int new_list_length, char portion2, char *portion3, int new_sock)
{
    char buffer_send[MAX_BUFFER];
    int n;
    switch (portion2)
    {
    case '!':
        sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            break;
        }
        sprintf(buffer_send, "%s\n", "*************************************************************************************");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            break;
        }
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].id, portion3) == 0)
            {
                continue;
            }
            else
            {
                sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                        list[i].id, list[i].phone, list[i].debt, list[i].date);
                n = send(new_sock, buffer_send, strlen(buffer_send), 0);
                if (n < 0)
                {
                    perror("Server error sending data");
                    break;
                }
            }
        }
        break;
    case '=':
        sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            break;
        }
        sprintf(buffer_send, "%s\n", "*************************************************************************************");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            break;
        }
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].id, portion3) == 0)
            {
                sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                        list[i].id, list[i].phone, list[i].debt, list[i].date);
                n = send(new_sock, buffer_send, strlen(buffer_send), 0);
                if (n < 0)
                {
                    perror("Server error sending data");
                    break;
                }
            }
        }
        break;
    case '<':
        sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            break;
        }
        sprintf(buffer_send, "%s\n", "*************************************************************************************");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            break;
        }
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].id, portion3) < 0)
            {
                sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                        list[i].id, list[i].phone, list[i].debt, list[i].date);
                n = send(new_sock, buffer_send, strlen(buffer_send), 0);
                if (n < 0)
                {
                    perror("Server error sending data");
                    break;
                }
            }
        }
        break;
    case '>':
        sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            break;
        }
        sprintf(buffer_send, "%s\n", "*************************************************************************************");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            break;
        }
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].id, portion3) > 0)
            {
                sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                        list[i].id, list[i].phone, list[i].debt, list[i].date);
                n = send(new_sock, buffer_send, strlen(buffer_send), 0);
                if (n < 0)
                {
                    perror("Server error sending data");
                    break;
                }
            }
        }
        break;
    default:
        break;
    }
}

void phone_operator_server(Customer *list, int new_list_length, char portion2, char *portion3, int new_sock)
{
    char buffer_send[MAX_BUFFER];
    int n;
    switch (portion2)
    {
    case '!':
        sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            break;
        }
        sprintf(buffer_send, "%s\n", "*************************************************************************************");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            break;
        }
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].phone, portion3) == 0)
            {
                continue;
            }
            else
            {
                sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                        list[i].id, list[i].phone, list[i].debt, list[i].date);
                n = send(new_sock, buffer_send, strlen(buffer_send), 0);
                if (n < 0)
                {
                    perror("Server error sending data");
                    break;
                }
            }
        }
        break;
    case '=':
        sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            break;
        }
        sprintf(buffer_send, "%s\n", "*************************************************************************************");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            break;
        }
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].phone, portion3) == 0)
            {
                sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                        list[i].id, list[i].phone, list[i].debt, list[i].date);
                n = send(new_sock, buffer_send, strlen(buffer_send), 0);
                if (n < 0)
                {
                    perror("Server error sending data");
                    break;
                }
            }
        }
        break;
    case '<':
        sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            break;
        }
        sprintf(buffer_send, "%s\n", "*************************************************************************************");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            break;
        }
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].phone, portion3) < 0)
            {
                sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                        list[i].id, list[i].phone, list[i].debt, list[i].date);
                n = send(new_sock, buffer_send, strlen(buffer_send), 0);
                if (n < 0)
                {
                    perror("Server error sending data");
                    break;
                }
            }
        }
        break;
    case '>':
        sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            break;
        }
        sprintf(buffer_send, "%s\n", "*************************************************************************************");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            break;
        }
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].phone, portion3) > 0)
            {
                sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                        list[i].id, list[i].phone, list[i].debt, list[i].date);
                n = send(new_sock, buffer_send, strlen(buffer_send), 0);
                if (n < 0)
                {
                    perror("Server error sending data");
                    break;
                }
            }
        }
        break;
    default:
        break;
    }
}

void debt_operator_server(Customer *list, int new_list_length, char portion2, char *portion3, int new_sock)
{
    char buffer_send[MAX_BUFFER];
    int n;
    float f_portion3 = atof(portion3);

    switch (portion2)
    {
    case '!':
        sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            break;
        }
        sprintf(buffer_send, "%s\n", "*************************************************************************************");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            break;
        }
        for (int i = 0; i < new_list_length; i++)
        {
            if (list[i].debt == f_portion3)
            {
                continue;
            }
            else
            {
                sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                        list[i].id, list[i].phone, list[i].debt, list[i].date);
                n = send(new_sock, buffer_send, strlen(buffer_send), 0);
                if (n < 0)
                {
                    perror("Server error sending data");
                    break;
                }
            }
        }
        break;
    case '=':
        sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            break;
        }
        sprintf(buffer_send, "%s\n", "*************************************************************************************");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            break;
        }
        for (int i = 0; i < new_list_length; i++)
        {
            if (list[i].debt == f_portion3)
            {
                sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                        list[i].id, list[i].phone, list[i].debt, list[i].date);
                n = send(new_sock, buffer_send, strlen(buffer_send), 0);
                if (n < 0)
                {
                    perror("Server error sending data");
                    break;
                }
            }
        }
        break;
    case '<':
        sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            break;
        }
        sprintf(buffer_send, "%s\n", "*************************************************************************************");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            break;
        }
        for (int i = 0; i < new_list_length; i++)
        {
            if (list[i].debt > f_portion3)
            {
                sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                        list[i].id, list[i].phone, list[i].debt, list[i].date);
                n = send(new_sock, buffer_send, strlen(buffer_send), 0);
                if (n < 0)
                {
                    perror("Server error sending data");
                    break;
                }
            }
        }
        break;
    case '>':
        sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            break;
        }
        sprintf(buffer_send, "%s\n", "*************************************************************************************");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            break;
        }
        for (int i = 0; i < new_list_length; i++)
        {
            if (list[i].debt < f_portion3)
            {
                sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                        list[i].id, list[i].phone, list[i].debt, list[i].date);
                n = send(new_sock, buffer_send, strlen(buffer_send), 0);
                if (n < 0)
                {
                    perror("Server error sending data");
                    break;
                }
            }
        }
        break;
    default:
        break;
    }
}

void date_operator_server(Customer *list, int new_list_length, char portion2, char *portion3, int new_sock)
{
    char buffer_send[MAX_BUFFER];
    int n;
    switch (portion2)
    {
    case '!':
        sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            break;
        }
        sprintf(buffer_send, "%s\n", "*************************************************************************************");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            break;
        }
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].date, portion3) == 0)
            {
                continue;
            }
            else
            {
                sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                        list[i].id, list[i].phone, list[i].debt, list[i].date);
                n = send(new_sock, buffer_send, strlen(buffer_send), 0);
                if (n < 0)
                {
                    perror("Server error sending data");
                    break;
                }
            }
        }
        break;
    case '=':
        sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            break;
        }
        sprintf(buffer_send, "%s\n", "*************************************************************************************");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            break;
        }
        for (int i = 0; i < new_list_length; i++)
        {
            if (strcmp(list[i].date, portion3) == 0)
            {
                sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                        list[i].id, list[i].phone, list[i].debt, list[i].date);
                n = send(new_sock, buffer_send, strlen(buffer_send), 0);
                if (n < 0)
                {
                    perror("Server error sending data");
                    break;
                }
            }
        }
        break;
    case '<':;
        sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            break;
        }
        sprintf(buffer_send, "%s\n", "*************************************************************************************");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            break;
        }
        char new_string_smaller[11];
        strcpy(new_string_smaller, portion3);
        char *d1 = strtok(new_string_smaller, "/");
        char *m1 = strtok(NULL, "/");
        char *y1 = strtok(NULL, "/");

        char temp_string_smaller[11];

        for (int i = 0; i < new_list_length; i++)
        {
            strcpy(temp_string_smaller, list[i].date);
            char *d2 = strtok(temp_string_smaller, "/");
            char *m2 = strtok(NULL, "/");
            char *y2 = strtok(NULL, "/");

            if (strcmp(y2, y1) < 0)
            {
                sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                        list[i].id, list[i].phone, list[i].debt, list[i].date);
                n = send(new_sock, buffer_send, strlen(buffer_send), 0);
                if (n < 0)
                {
                    perror("Server error sending data");
                    break;
                }
            }
            if (strcmp(y2, y1) == 0)
            {
                if (strcmp(m2, m1) < 0)
                {
                    sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                            list[i].id, list[i].phone, list[i].debt, list[i].date);
                    n = send(new_sock, buffer_send, strlen(buffer_send), 0);
                    if (n < 0)
                    {
                        perror("Server error sending data");
                        break;
                    }
                }
            }
            if (strcmp(y2, y1) == 0)
            {
                if (strcmp(m2, m1) == 0)
                {
                    if (strcmp(d2, d1) < 0)
                    {
                        sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                                list[i].id, list[i].phone, list[i].debt, list[i].date);
                        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
                        if (n < 0)
                        {
                            perror("Server error sending data");
                            break;
                        }
                    }
                }
            }
        }
        break;
    case '>':;
        sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15s%-15s\n", "First Name", "Last Name", "ID", "Phone", "Debt", "Date");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            break;
        }
        sprintf(buffer_send, "%s\n", "*************************************************************************************");
        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
        if (n < 0)
        {
            perror("Server error sending data");
            break;
        }
        char new_string_bigger[11];
        strcpy(new_string_bigger, portion3);
        char *d_1 = strtok(new_string_bigger, "/");
        char *m_1 = strtok(NULL, "/");
        char *y_1 = strtok(NULL, "/");

        char temp_string_bigger[11];

        for (int i = 0; i < new_list_length; i++)
        {
            strcpy(temp_string_bigger, list[i].date);
            char *d_2 = strtok(temp_string_bigger, "/");
            char *m_2 = strtok(NULL, "/");
            char *y_2 = strtok(NULL, "/");

            if (strcmp(y_2, y_1) > 0)
            {
                sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                        list[i].id, list[i].phone, list[i].debt, list[i].date);
                n = send(new_sock, buffer_send, strlen(buffer_send), 0);
                if (n < 0)
                {
                    perror("Server error sending data");
                    break;
                }
            }
            if (strcmp(y_2, y_1) == 0)
            {
                if (strcmp(m_2, m_1) > 0)
                {
                    sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                            list[i].id, list[i].phone, list[i].debt, list[i].date);
                    n = send(new_sock, buffer_send, strlen(buffer_send), 0);
                    if (n < 0)
                    {
                        perror("Server error sending data");
                        break;
                    }
                }
            }
            if (strcmp(y_2, y_1) == 0)
            {
                if (strcmp(m_2, m_1) == 0)
                {
                    if (strcmp(d_2, d_1) > 0)
                    {
                        sprintf(buffer_send, "%-15s%-15s%-15s%-15s%-15.2f%-15s\n", list[i].first_name, list[i].last_name,
                                list[i].id, list[i].phone, list[i].debt, list[i].date);
                        n = send(new_sock, buffer_send, strlen(buffer_send), 0);
                        if (n < 0)
                        {
                            perror("Server error sending data");
                            break;
                        }
                    }
                }
            }
        }
        break;
    default:
        break;
    }
}
