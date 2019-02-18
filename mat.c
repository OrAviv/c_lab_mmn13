//
// Created by Or Aviv on 2019-02-11.
//
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mat.h"

#define MAT_ROW_SIZE 4
#define MAT_COLUMN_SIZE 4
#define MAX_PRINT_SIZE 1000000

mat MAT_A = {0};
mat MAT_B = {0};
mat MAT_C = {0};
mat MAT_D = {0};
mat MAT_E = {0};
mat MAT_F = {0};


mat *get_matrix(char* mat_name)
{
    if(strcmp(mat_name, "MAT_A"))
        return &MAT_A;
    if(strcmp(mat_name, "MAT_B"))
        return &MAT_B;
    if(strcmp(mat_name, "MAT_C"))
        return &MAT_C;
    if(strcmp(mat_name, "MAT_D"))
        return &MAT_D;
    if(strcmp(mat_name, "MAT_E"))
        return &MAT_E;
    if(strcmp(mat_name, "MAT_F"))
        return &MAT_F;
    else
        return NULL;
}

void get_word(char *word)
{
    int c;
    int i = 0;
    while ((c = getchar()) != ' ' && c != ',' && c != EOF)
    {
        word[i] = (char)c;
    }
}


/*sets mat_result to mat_a*/
void set_mat (mat *mat_a, mat *mat_result)
{
    for (int i = 0; i < MAT_ROW_SIZE; i++)
    {
        for (int j = 0; j < MAT_COLUMN_SIZE; j++)
        {
            *mat_result[i][j] = *mat_a[i][j];
        }
    }
}

void read_mat (mat *mat_a, ...)
{
    va_list ap; /*points to each unnamed argument in turn*/
    va_start(ap, mat_a);
    for (int i = 0; i < MAT_ROW_SIZE; i++)
    {
        for (int j = 0; j < MAT_COLUMN_SIZE; j++)
        {
            *mat_a[i][j] = va_arg(ap, double);
        }
    }
    va_end(ap);
}

void print_mat (mat *mat_a)
{
    for (int i = 0; i < MAT_ROW_SIZE; i++)
    {
        for (int j = 0; j < MAT_COLUMN_SIZE; j++)
        {
            if (*mat_a[i][j] >= MAX_PRINT_SIZE)
                printf("%.2f ",*mat_a[i][j]);
            else
                printf("%-7.2f ",*mat_a[i][j]);
        }
        printf("\n");
    }
}

void add_mat (mat *mat_a, mat *mat_b, mat *mat_result)
{
    for (int i = 0; i < MAT_ROW_SIZE; i++)
    {
        for (int j = 0; j < MAT_COLUMN_SIZE; j++)
        {
            *mat_result[i][j] = *mat_a[i][j] + *mat_b[i][j];
        }
    }
}

void sub_mat (mat *mat_a, mat *mat_b, mat *mat_result)
{
    for (int i = 0; i < MAT_ROW_SIZE; i++)
    {
        for (int j = 0; j < MAT_COLUMN_SIZE; j++)
        {
            *mat_result[i][j] = *mat_a[i][j] - *mat_b[i][j];
        }
    }
}
/*mat_res_helper helps us if mat_result happens to be mat_a or mat_b;
 * therefor we need it otherwise the calculation will be wrong*/
void mul_mat (mat *mat_a, mat *mat_b, mat *mat_result)
{
    mat mat_res_helper = {0};

    for (int i = 0; i < MAT_ROW_SIZE; i++)
    {
        for (int j = 0; j < MAT_COLUMN_SIZE; j++)
        {
            for (int k = 0; k < MAT_ROW_SIZE; k++)
            {
                mat_res_helper[i][j] += (*mat_a[i][k]) * (*mat_b[k][j]);
            }
        }
    }

    set_mat(&mat_res_helper, mat_result);
}

void mul_scalar (mat *mat_a, double multiplyer, mat *mat_result)
{
    for (int i = 0; i < MAT_ROW_SIZE; i++)
    {
        for (int j = 0; j < MAT_COLUMN_SIZE; j++)
        {
            *mat_result[i][j] = *mat_a[i][j] * multiplyer;
        }
    }
}

void trans_mat (mat *mat_a, mat *mat_result)
{
    mat mat_res_helper = {0};

    for (int i = 0; i < MAT_ROW_SIZE; i++)
    {
        for (int j = 0; j < MAT_COLUMN_SIZE; j++)
        {
            mat_res_helper[j][i] = *mat_a[i][j];
        }
    }

    set_mat(&mat_res_helper, mat_result);
}