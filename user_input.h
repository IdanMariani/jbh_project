#ifndef USER_INPUT_H
#define USER_INPUT_H

#include "general.h"
#include "select_operator.h"
#include "validate.h"

void error_handle(char *buffer, char *portion2, char *portion3, bool *error_input, enum Compiler comp);
#endif