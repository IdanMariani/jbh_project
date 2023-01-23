#ifndef VALIDATE_H
#define VALIDATE_H

#include "general.h"
#include "read_csv.h"

bool is_letter(char c);
bool is_number(char c);
bool validate_name(char *name);
bool validate_lastname(char *lastname);
bool validate_id(char *id);



#endif