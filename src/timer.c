/*
** EPITECH PROJECT, 2023
** My_Radar
** File description:
** Timer
*/

#include "all_headers.h"
#include <SFML/Graphics.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

void update_timer(Manager* manager, sfClock* clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    int seconds = (int)sfTime_asSeconds(time);
    char time_str[32];
    char display_str[64] = "Simulaton time : ";

    my_long_to_string((long)seconds, time_str);
    my_strcat(display_str, time_str);
    sfText_setString(manager->timer_text, display_str);
}
