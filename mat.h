//
// Created by Or Aviv on 2019-02-11.
//

#ifndef MAMAN13_MAT_H
#define MAMAN13_MAT_H

typedef double mat[4][4];

void clean_string (char* string, int size_of_clean);
void get_command_name(char* string, char* command_name, int* i);
void get_mat_name(char* string, char* mat_name, int* i);
double parse_double_from_string (char* string, int* i);
mat *get_matrix(char* mat_name);

void read_mat (mat *mat_a, char* string, int* index);
void print_mat (mat *mat_a);
void add_mat (mat *mat_a, mat *mat_b, mat *mat_result);
void sub_mat (mat *mat_a, mat *mat_b, mat *mat_result);
void mul_mat (mat *mat_a, mat *mat_b, mat *mat_result);
void mul_scalar (mat *mat_a, double multiplyer, mat *mat_result);
void trans_mat (mat *mat_a, mat *mat_result);

#endif //MAMAN13_MAT_H
