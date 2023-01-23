#ifndef READ_CSV_H
#define READ_CSV_H

#include "general.h"
#include "validate.h"

void find_max_lines(FILE *file, int *max_lines);
int read_from_csv_file(FILE *file, Customer *customers);
bool find_highest_date(char *date1, char *date2);




#endif