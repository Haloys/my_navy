/*
** EPITECH PROJECT, 2023
** Main Header
** File description:
** Lib principale
*/

#include <stdarg.h>
#include <dirent.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>

#ifndef MY_H_
    #define MY_H_

int my_putchar(char c);
int my_put_nbr(int number_put);
int my_putstr(char const *str);
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);
int my_strcmp(const char *str1, const char *str2);
int my_getnbr(char const *str);
int mini_printf(const char *format, ...);
void concat_path(char *destination, const char *path1, const char *path2);
void my_long_to_string(long num, char *str);
void reverse_string(char *str);
void my_long_to_string(long num, char *str);
void digit_to_str(int digit, char *str);

#endif
