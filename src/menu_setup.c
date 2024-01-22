/*
** EPITECH PROJECT, 2024
** My_Radar
** File description:
** Menu_Setup
*/

#include "all_headers.h"
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

button buton(const char *path, float sl, sfVector2f pos, const AppConfig *fig)
{
    button button;
    sfVector2u button_size;
    float centered_x;

    button.texture = sfTexture_createFromFile(path, NULL);
    button.sprite = sfSprite_create();
    sfSprite_setTexture(button.sprite, button.texture, sfTrue);
    button_size = sfTexture_getSize(button.texture);
    button.scale = sl;
    sfSprite_setScale(button.sprite, (sfVector2f){sl, sl});
    centered_x = (fig->window_width - (button_size.x * sl)) / 2.0f;
    sfSprite_setPosition(button.sprite, (sfVector2f)
    {centered_x + pos.x, pos.y});
    return button;
}

void cleanup_button(button* button)
{
    if (button->sprite) {
        sfSprite_destroy(button->sprite);
    }
    if (button->texture) {
        sfTexture_destroy(button->texture);
    }
}

menu init_menu(sfRenderWindow* window, const AppConfig* fig)
{
    menu menu;

    menu.startButton = buton("assets/images/menu/start.png"
    , 0.65f, (sfVector2f){0, (3 * fig->window_height / 8)}, fig);
    menu.quitButton = buton("assets/images/menu/quit.png"
    , 0.65f, (sfVector2f){0, (5 * fig->window_height / 8)}, fig);
    menu.bgSprite = init_bg("assets/images/menu/backgrnd.png"
    , fig->window_width, fig->window_height);
    return menu;
}

void cleanup_menu(menu* menu)
{
    cleanup_button(&menu->startButton);
    cleanup_button(&menu->quitButton);
    sfSprite_destroy(menu->bgSprite);
}

void render_menu(sfRenderWindow* window, menu* menu)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, menu->bgSprite, NULL);
    sfRenderWindow_drawSprite(window, menu->startButton.sprite, NULL);
    sfRenderWindow_drawSprite(window, menu->quitButton.sprite, NULL);
    sfRenderWindow_display(window);
}
