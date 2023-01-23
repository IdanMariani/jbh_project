#ifndef VALIDATE_H
#define VALIDATE_H

#include "general.h"
#include "read_csv.h"

bool is_letter(char c);
bool is_number(char c);
bool validate_name(char *name);
bool validate_lastname(char *lastname);
bool validate_id(char *id);
bool validate_phone_number(char *number);
bool validate_debt(char *number);
bool validate_date(char *date);



#endif