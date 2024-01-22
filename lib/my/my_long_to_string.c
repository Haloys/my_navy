/*
** EPITECH PROJECT, 2023
** Main lib
** File description:
** My_long_to_string
*/

void reverse_string(char *str)
{
    int length = 0;
    char temp = 0;

    while (str[length] != '\0') {
        length++;
    }
    for (int i = 0; i < length / 2; i++) {
        temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
}

void prepare_number_for_conversion(long *num, int *is_negative)
{
    if (*num < 0) {
        *is_negative = 1;
        *num = -(*num);
    } else {
        *is_negative = 0;
    }
}

void convert_number_to_string(long num, char *str, int is_negative)
{
    int i = 0;

    while (num != 0) {
        str[i] = (num % 10) + '0';
        i++;
        num /= 10;
    }
    if (i == 0) {
        str[i] = '0';
        i++;
    }
    if (is_negative) {
        str[i] = '-';
        i++;
    }
    str[i] = '\0';
    reverse_string(str);
}

void my_long_to_string(long num, char *str)
{
    int is_negative;

    prepare_number_for_conversion(&num, &is_negative);
    convert_number_to_string(num, str, is_negative);
}
