/*
** EPITECH PROJECT, 2023
** My_Radar
** File description:
** Parsing_Utils
*/

#include "all_headers.h"
#include <SFML/Graphics.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void skip_whitespace_and_parse_sign(char **str, float *sign)
{
    while (**str == ' ') {
        (*str)++;
    }
    if (**str == '-') {
        *sign = -1.0f;
        (*str)++;
    } else if (**str == '+') {
        (*str)++;
    }
}

float parse_float(char **str)
{
    float result = 0.0f;
    float scale = 0.1f;
    float sign = 1.0f;

    skip_whitespace_and_parse_sign(str, &sign);
    while (**str >= '0' && **str <= '9') {
        result = result * 10.0f + (**str - '0');
        (*str)++;
    }
    if (**str == '.') {
        (*str)++;
        while (**str >= '0' && **str <= '9') {
            result += (**str - '0') * scale;
            scale *= 0.1f;
            (*str)++;
        }
    }
    return result * sign;
}

int parse_int(char **str)
{
    int result = 0;
    int sign = 1;

    while (**str == ' ') {
        (*str)++;
    }
    if (**str == '-') {
        sign = -1;
        (*str)++;
    } else if (**str == '+') {
        (*str)++;
    }
    while (**str >= '0' && **str <= '9') {
        result = result * 10 + (**str - '0');
        (*str)++;
    }
    return result * sign;
}
