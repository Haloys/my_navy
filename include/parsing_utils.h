/*
** EPITECH PROJECT, 2023
** My_Radar
** File description:
** Parsing_Utils
*/

#ifndef PARSING_UTILS_H
    #define PARSING_UTILS_H

    #include "manager_structs.h"

void skip_whitespace_and_parse_sign(char **str, float *sign);
float parse_float(char **str);
int parse_int(char **str);

#endif // PARSING_UTILS_H
