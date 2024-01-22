/*
** EPITECH PROJECT, 2024
** My_Radar
** File description:
** Ui_Function
*/

#ifndef UI_FUNCTIONS_H_
    #define UI_FUNCTIONS_H_

    #include "struct_menu.h"
    #include "struct_button.h"

sfSound *init_audio(const char *file_path);
int refa(const sfEvent* event, const sfVector2i* mouse, const button* button);
int process_menu_events(sfRenderWindow* window, menu* menu);
int show_menu(sfRenderWindow* window, const AppConfig* fig);
button buton(const char *path, float sl, sfVector2f pos, const AppConfig *fig);
void cleanup_button(button* button);
menu init_menu(sfRenderWindow* window, const AppConfig* fig);
void cleanup_menu(menu* menu);
void render_menu(sfRenderWindow* window, menu* menu);
sfSprite *init_bg(const char *filepath, int win_width, int win_height);

#endif // UI_FUNCTIONS_H_
