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
#define STR_NUMBER_SIZE  sizeof(double)
#define MAX_STRING_SIZE 800000


mat MAT_A = {0};
mat MAT_B = {0};
mat MAT_C = {0};
mat MAT_D = {0};
mat MAT_E = {0};
mat MAT_F = {0};

void clean_string (char* string , int size_of_clean)
{
    for (int i = 0; i < size_of_clean; i++)
    {
        string[i] = ' ';
    }
}

void get_command_name(char* string, char* command_name, int* i)
{
    while (string[*i] != ' ')
    {
        if (string[*i] == ',')
        {
            printf("illegal comma");
            *command_name = (char)NULL;
            break;
        }
        command_name[*i] = string[*i];
        (*i)++;
    }
}

void get_mat_name(char* string, char* mat_name, int* i)
{
    int indicator = 0;
    while (string[*i] == ' ')
    {
        (*i)++;
        if (string[*i] == ',')
        {
            printf("Missing parameter");
            return;
        }
    }

    if (string[*i] == ',')
    {
        printf("illegal comma");
        return;
    }

    while (string[*i] != ',' && string[*i] != '\n')
    {
        mat_name[indicator] = string[*i];
        indicator++;
        (*i)++;
    }

    if (string[*i] != '\n')
        (*i)++;
}

double parse_double_from_string (char* string, int* i)
{
    char* str_number = malloc(STR_NUMBER_SIZE);
    int indicator = 0;
    while (string[*i] == ' ')
    {
        (*i)++;
        if ((string[*i] > '9' || string[*i] < '0') && string[*i] != '-')
        {
            printf("Parameter is not a real number");
            //return 0 as NULL
            free(str_number);
            return 0;
        }
    }
    if (string[*i] == ',')
    {
        printf("illegal comma");
        free(str_number);
        //return 0 as NULL
        return 0;
    }

    while (string[*i] != ',' && string[*i] != '\n')
    {
        str_number[indicator] = string[*i];
        indicator++;
        (*i)++;
    }

    if (string[*i] != '\n')
        (*i)++;
    double return_value = atof(str_number);
    free(str_number);
    return return_value;
}


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

void read_mat (mat *my_mat, char* string, int* index)
{
    double value = 0;
    for (int i = 0; i < MAT_ROW_SIZE; i++)
    {
        for (int j = 0; j < MAT_COLUMN_SIZE; j++)
        {
            if (string[*index] == '\n')
                return;
            value = parse_double_from_string(string, index);
            if (!value)
                return;
            *my_mat[i][j] = value;
        }
    }
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