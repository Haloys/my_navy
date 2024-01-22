/*
** EPITECH PROJECT, 2023
** My_Radar
** File description:
** Game_Loop
*/

#include "all_headers.h"
#include <SFML/Graphics.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Clock.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool is_game_over(Manager *manager)
{
    for (int i = 0; i < manager->entity_count; ++i) {
        if (manager->entities[i].type == PLANE &&
            manager->entities[i].is_active) {
            return false;
        }
    }
    return true;
}

void game_over_text(Manager* manager, sfRenderWindow* win, const AppConfig* ig)
{
    const char *display_str = "Simulation Over!";
    int textSize = 48;
    sfColor textColor = sfWhite;
    sfVector2f position = {ig->window_width / 2.0f, ig->window_height / 2.5f};
    sfFloatRect textRect;

    sfText_setString(manager->game_over_text, display_str);
    sfText_setCharacterSize(manager->game_over_text, textSize);
    sfText_setColor(manager->game_over_text, textColor);
    textRect = sfText_getLocalBounds(manager->game_over_text);
    sfText_setOrigin(manager->game_over_text,
    (sfVector2f){textRect.width / 2.0f, textRect.height / 2.0f});
    sfText_setPosition(manager->game_over_text, position);
    sfRenderWindow_drawText(win, manager->game_over_text, NULL);
}

void timer(Manager* man, float delta_time, const AppConfig *ig, sfClock* t)
{
    update_ent(man, delta_time, ig->window_width, ig->window_height);
    if (man->update_timer) {
        update_timer(man, t);
    }
}

void handle_game_over(Manager* man, sfRenderWindow* win, const AppConfig *ig)
{
    if (is_game_over(man)) {
        man->game_over = true;
        game_over_text(man, win, ig);
        man->update_timer = false;
    }
}

void run_game_loop(sfRenderWindow* win, Manager* manager, const AppConfig *ig)
{
    sfClock* game_clock = sfClock_create();
    sfClock* time_clock = sfClock_create();
    sfEvent event;
    sfTime time;
    float delta_time;

    while (sfRenderWindow_isOpen(win)) {
        handle_events(win, &event, manager);
        time = sfClock_restart(game_clock);
        delta_time = sfTime_asSeconds(time);
        if (!manager->game_over && !manager->is_paused) {
            timer(manager, delta_time, ig, time_clock);
            handle_game_over(manager, win, ig);
        }
        render(win, manager, ig);
    }
    sfClock_destroy(game_clock);
    sfClock_destroy(time_clock);
}
