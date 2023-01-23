#ifndef READ_CSV_H
#define READ_CSV_H

#include "general.h"
#include "validate.h"

void find_max_lines(FILE *file, int *max_lines);
int read_from_csv_file(FILE *file, Customer *customers);




#endif