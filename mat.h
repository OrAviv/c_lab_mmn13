//
// Created by Or Aviv on 2019-02-11.
//

#ifndef MAMAN13_MAT_H
#define MAMAN13_MAT_H

typedef double mat[4][4];


void read_mat (mat *mat_a, ...);
void print_mat (mat *mat_a);
void add_mat (mat *mat_a, mat *mat_b, mat *mat_result);
void sub_mat (mat *mat_a, mat *mat_b, mat *mat_result);
void mul_mat (mat *mat_a, mat *mat_b, mat *mat_result);
void mul_scalar (mat *mat_a, double multiplyer, mat *mat_result);
void trans_mat (mat *mat_a, mat *mat_result);
void stop ();

char *function_name_parser(char *);


#endif //MAMAN13_MAT_H
