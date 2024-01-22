/*
** EPITECH PROJECT, 2024
** My_Radar
** File description:
** Struct_Menu
*/

#ifndef STRUCT_MENU_H
    #define STRUCT_MENU_H

    #include "struct_button.h"

typedef struct {
    sfSprite* bgSprite;
    sfSprite* bgmSprite;
    button quitdefButton;
    button startButton;
    button quitButton;
    button menuButton;
    sfSprite* logoSprite;
} menu;

#endif
