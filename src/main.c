/*
** EPITECH PROJECT, 2023
** My_Radar
** File description:
** Main
*/

#include "all_headers.h"
#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void setup_game(sfRenderWindow **window, Manager *manager, const char *path)
{
    AppConfig config = {1920, 1080};
    sfVideoMode mode = {config.window_width, config.window_height, 32};
    sfVector2u texture_size;
    sfVector2u window_size;

    *window = sfRenderWindow_create(mode, "My_Radar", sfResize |
                                    sfClose, NULL);
    manager->bg_texture = sfTexture_createFromFile("assets/map.png", NULL);
    manager->bg_sprite = sfSprite_create();
    sfSprite_setTexture(manager->bg_sprite, manager->bg_texture, sfTrue);
    texture_size = sfTexture_getSize(manager->bg_texture);
    window_size = sfRenderWindow_getSize(*window);
    sfSprite_setScale(manager->bg_sprite,
    (sfVector2f){(float)window_size.x / texture_size.x,
    (float)window_size.y / texture_size.y});
    init_manager_basic(manager);
    init_manager_text_elements(manager, *window);
    load_textures(manager);
    parse_script(path, manager);
}

void cleanup_game(sfRenderWindow* window, Manager* manager)
{
    cleanup(manager);
    if (manager->timer_font != NULL) {
        sfFont_destroy(manager->timer_font);
    }
    if (manager->timer_text != NULL) {
        sfText_destroy(manager->timer_text);
    }
    if (manager->timer_font != NULL) {
        sfFont_destroy(manager->timer_font);
    }
    if (manager->timer_text != NULL) {
        sfText_destroy(manager->timer_text);
    }
    if (manager->game_over_text != NULL) {
        sfText_destroy(manager->game_over_text);
    }
    sfRenderWindow_destroy(window);
}

void display_usage(void)
{
    mini_printf("Air traffic simulation panel\n");
    mini_printf("\nUSAGE\n     ./my_radar [OPTIONS] path_to_script\n");
    mini_printf("     path_to_script       The path to the script file.\n");
    mini_printf("\nOPTIONS\n");
    mini_printf(" -h              print the usage and quit.\n");
    mini_printf("\nUSER INTERACTIONS\n");
    mini_printf(" ‘L’ key enable/disable hitboxes and areas.\n");
    mini_printf(" 'S’ key enable/disable sprites.\n");
    mini_printf(" 'P' key enable/disable pause menu");
    exit(0);
}

int process_args(int argc, char **argv)
{
    if (argc < 2) {
        mini_printf("Usage: %s path_to_script\n", argv[0]);
        return 84;
    }
    if (my_strcmp(argv[1], "-h") == 0) {
        display_usage();
        return 0;
    }
    return 0;
}

int main(int argc, char **argv)
{
    sfRenderWindow* window;
    Manager manager;
    AppConfig config = {1920, 1080};
    int menu_status;

    process_args(argc, argv);
    setup_game(&window, &manager, argv[1]);
    if (window) {
        menu_status = show_menu(window, &config);
        if (menu_status == 1) {
            run_game_loop(window, &manager, &config);
            init_manager_basic(&manager);
            init_manager_text_elements(&manager, window);
            cleanup_game(window, &manager);
        } else {
        sfRenderWindow_destroy(window);
        }
    }
    return 0;
}
