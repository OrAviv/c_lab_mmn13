#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "mat.h"


#define MAX_STRING_SIZE 800000000
#define MAX_COMMAND_SIZE 11
#define MAX_MAT_MAME 6


int main()
{

    char* input_string = malloc(sizeof(char)*MAX_STRING_SIZE);
    char* command_name = malloc(MAX_COMMAND_SIZE);
    char* first_mat_name = malloc(MAX_MAT_MAME);
    char* second_mat_name = malloc(MAX_MAT_MAME);
    char* result_mat_name = malloc(MAX_MAT_MAME);
    mat *first_mat;
    mat *second_mat;
    mat *result_mat;

    int* position_in_string;


    fgets(input_string, MAX_STRING_SIZE , stdin);

    while (strcmp(input_string, "stop") != 0)
    {
        *position_in_string = 0;

        get_command_name(input_string, command_name, position_in_string);

        if (strcmp(command_name, "add_mat") == 0)
        {
            get_mat_name(input_string, first_mat_name,position_in_string);
            first_mat = get_matrix(first_mat_name);
            get_mat_name(input_string, second_mat_name, position_in_string);
            second_mat = get_matrix(second_mat_name);
            get_mat_name(input_string, result_mat_name, position_in_string);
            result_mat = get_matrix(result_mat_name);
            if (first_mat == NULL || second_mat == NULL || result_mat == NULL)
            {
                printf("Undefined matrix name\n");
                continue;
            }
            add_mat(first_mat, second_mat, result_mat);

        }
        else if (strcmp(command_name, "sub_mat") == 0)
        {
            get_mat_name(input_string, first_mat_name,position_in_string);
            first_mat = get_matrix(first_mat_name);
            get_mat_name(input_string, second_mat_name, position_in_string);
            second_mat = get_matrix(second_mat_name);
            get_mat_name(input_string, result_mat_name, position_in_string);
            result_mat = get_matrix(result_mat_name);
            if (first_mat == NULL || second_mat == NULL || result_mat == NULL)
            {
                printf("Undefined matrix name\n");
                continue;
            }
            sub_mat(first_mat, second_mat, result_mat);
        }
        else if (strcmp(command_name, "mul_mat") == 0)
        {
            get_mat_name(input_string, first_mat_name,position_in_string);
            first_mat = get_matrix(first_mat_name);
            get_mat_name(input_string, second_mat_name, position_in_string);
            second_mat = get_matrix(second_mat_name);
            get_mat_name(input_string, result_mat_name, position_in_string);
            result_mat = get_matrix(result_mat_name);
            if (first_mat == NULL || second_mat == NULL || result_mat == NULL)
            {
                printf("Undefined matrix name\n");
                continue;
            }
            mul_mat(first_mat,second_mat, first_mat);
        }
        else if (strcmp(command_name, "mul_scalar") == 0)
        {
            double multiplayer = 0;
            get_mat_name(input_string, first_mat_name, position_in_string);
            first_mat = get_matrix(first_mat_name);
            multiplayer = parse_double_from_string(input_string, position_in_string);
            if (!multiplayer)
                continue;
            get_mat_name(input_string, result_mat_name, position_in_string);
            result_mat = get_matrix(result_mat_name);
            if (first_mat == NULL || result_mat == NULL)
            {
                printf("Undefined matrix name\n");
                continue;
            }
            mul_scalar(first_mat, multiplayer, result_mat);

        }
        else if (strcmp(command_name, "trans_mat") == 0)
        {
            get_mat_name(input_string, first_mat_name, position_in_string);
            first_mat = get_matrix(first_mat_name);
            get_mat_name(input_string, result_mat_name, position_in_string);
            result_mat = get_matrix(result_mat_name);
            if (first_mat == NULL || result_mat == NULL)
            {
                printf("Undefined matrix name\n");
                continue;
            }
            trans_mat(first_mat, result_mat);
        }
        else if (strcmp(command_name, "read_mat") == 0)
        {
            get_mat_name(input_string, first_mat_name, position_in_string);
            first_mat = get_matrix(first_mat_name);
            if (first_mat == NULL)
            {
                printf("Undefined matrix name\n");
                continue;
            }
            read_mat(first_mat, input_string, position_in_string);

        }
        else if (strcmp(command_name, "print_mat") == 0)
        {
            get_mat_name(input_string, first_mat_name, position_in_string);
            first_mat = get_matrix(first_mat_name);
            if (first_mat == NULL)
            {
                printf("Undefined matrix name\n");
                continue;
            }

            print_mat(first_mat);
        }

        else
            printf("Undefined command name \n");

        clean_string(command_name, MAX_COMMAND_SIZE);
        fgets(input_string, MAX_STRING_SIZE , stdin);

    }

    free(input_string);
    free(command_name);
    free(first_mat_name);
    free(second_mat_name);
    free(result_mat_name);
}