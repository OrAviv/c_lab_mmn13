#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "mat.h"


#define MAX_COMMAND_SIZE 8000
#define MAX_FUNCTION_NAME 11
#define MAX_MAT_MAME 6

//int main() {
//
//    mat MAT_A = {0};
//    mat MAT_B = {0};
//    mat MAT_C = {0};
//    mat MAT_D = {0};
//    mat MAT_E = {0};
//    mat MAT_F = {0};
//
//    char* command = malloc(MAX_COMMAND_SIZE);
//    char* function_name  = malloc(MAX_FUNCTION_NAME);
//    char* first_mat_name = malloc(MAX_MAT_MAME);
//    char* second_mat_name = malloc(MAX_MAT_MAME);
//    char* result_mat_name = malloc(MAX_MAT_MAME);
//
//    while(*command != EOF)
//    {
//        first_mat_name = NULL;
//        second_mat_name = NULL;
//        result_mat_name = NULL;
//
//        scanf("%s",command);
//        int i = 0;
//        while(command[i] != ' ' && command[i] != ',')
//        {
//            function_name[i] = command[i];
//            i++;
//        }
//        function_name = function_name_parser(function_name);
//        if (strcmp(function_name, "Undefined command name"))
//        {
//            printf("%s",function_name);
//            continue;
//        }
//        //if (search_for_double_commas(command[i]) == true)
//        //      {
//        //          printf("Multiple consecutive commas");
//        //          continue;
//        //      }
//
//    }
//
//
//
//    free(command);
//    free(function_name);
//    free(first_mat_name);
//    free(second_mat_name);
//    free(result_mat_name);
//
//    return 0;
//}

int main()
{

    char* command = malloc(MAX_COMMAND_SIZE);
    char* function_name  = malloc(MAX_FUNCTION_NAME);
    char* first_mat_name = malloc(MAX_MAT_MAME);
    char* second_mat_name = malloc(MAX_MAT_MAME);
    char* result_mat_name = malloc(MAX_MAT_MAME);

    while (*command != EOF)
    {
        get_word(command);

        if (strcmp(command, "add_mat"))
        {
            get_word(first_mat_name);
            get_word(second_mat_name);
            get_word(result_mat_name);
        }
        else if (strcmp(command, "sub_mat"))
        {
            get_word(first_mat_name);
            get_word(second_mat_name);
            get_word(result_mat_name);
        }
        else if (strcmp(command, "mul_mat"))
        {
            get_word(first_mat_name);
            get_word(second_mat_name);
            get_word(result_mat_name);
        }
        else if (strcmp(command, "mul_scalar"))
        {
            get_word(first_mat_name);
            get_word(result_mat_name);

        }
        else if (strcmp(command, "trans_mat"))
        {
            get_word(first_mat_name);
            get_word(result_mat_name);
        }
        else
            printf("Undefined command name");

    }


}