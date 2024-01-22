/*
** EPITECH PROJECT, 2023
** Main lib
** File description:
** My_strcmp
*/

#include "my.h"

int lowercase(char c)
{
    if (c >= 'A' && c <= 'Z') {
        return c + 'a' - 'A';
    }
    return c;
}

int my_strcmp(const char *str1, const char *str2)
{
    int i = 0;

    while (lowercase(str1[i]) == lowercase(str2[i])) {
        if (str1[i] == '\0') {
            return 0;
        }
        i++;
    }
    return lowercase(str1[i]) - lowercase(str2[i]);
}
