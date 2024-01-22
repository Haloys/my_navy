/*
** EPITECH PROJECT, 2023
** Main lib
** File description:
** digit_to_str
*/

#include "my.h"

void digit_to_str(int digit, char *str)
{
    if (digit < 10) {
        str[0] = '0';
        str[1] = '0' + digit;
    } else {
        str[0] = '0' + digit / 10;
        str[1] = '0' + digit % 10;
    }
    str[2] = '\0';
}
