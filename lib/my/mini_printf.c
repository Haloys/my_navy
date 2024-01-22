/*
** EPITECH PROJECT, 2023
** Mini printf
** File description:
** Main
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "my.h"

int switch_test(const char c, va_list ap)
{
    switch (c) {
    case 'c' :
        my_putchar(va_arg(ap, int));
        break;
    case 's':
        my_putstr(va_arg(ap, char *));
        break;
    case 'd':
    case 'i':
        my_put_nbr(va_arg(ap, int));
        break;
    case '%':
        my_putchar('%');
        break;
    }
}

int mini_printf(const char *format, ...)
{
    va_list ap;
    int len = my_strlen(format);

    va_start(ap, format);
    for (int i = 0; i < len; i++) {
        if (format[i] == '%' && i + 1 < len) {
            switch_test(format[i + 1], ap);
            i++;
        } else {
            my_putchar(format[i]);
        }
    }
    va_end(ap);
    return 0;
}
