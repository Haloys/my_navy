/*
** EPITECH PROJECT, 2023
** My_Radar
** File description:
** Event_Handling
*/

#include "all_headers.h"
#include <SFML/Graphics.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void toggle_hitboxes(Manager* manager)
{
    manager->show_hitboxes = !manager->show_hitboxes;
}

void toggle_sprites(Manager* manager)
{
    manager->show_sprites = !manager->show_sprites;
}

void toggle_pause(Manager* manager)
{
    manager->is_paused = !manager->is_paused;
}

void handle_key_press_event(sfEvent* event, Manager* manager)
{
    switch (event->key.code) {
        case sfKeyL:
            toggle_hitboxes(manager);
            break;
        case sfKeyS:
            toggle_sprites(manager);
            break;
        case sfKeyP:
            toggle_pause(manager);
            break;
    }
}

void handle_events(sfRenderWindow* window, sfEvent* event, Manager* manager)
{
    while (sfRenderWindow_pollEvent(window, event)) {
        switch (event->type) {
            case sfEvtClosed:
                sfRenderWindow_close(window);
                break;
            case sfEvtKeyPressed:
                handle_key_press_event(event, manager);
                break;
        }
    }
}
