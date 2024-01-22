/*
** EPITECH PROJECT, 2024
** My_Radar
** File description:
** Struct_Button
*/

#ifndef STRUCT_BUTTON_H
    #define STRUCT_BUTTON_H

typedef struct {
    sfSprite* sprite;
    sfTexture* texture;
    sfVector2f position;
    float scale;
} button;

#endif // STRUCT_BUTTON_H
