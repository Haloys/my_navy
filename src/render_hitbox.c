/*
** EPITECH PROJECT, 2023
** My_Radar
** File description:
** Render_Hitbox
*/

#include "all_headers.h"
#include <SFML/Graphics.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

sfRectangleShape* set_hitbox(Entity* ent, float width, float height)
{
    sfRectangleShape* hitbox = sfRectangleShape_create();
    sfVector2f sprite_pos = sfSprite_getPosition(ent->sprite);
    sfVector2u text_size = sfTexture_getSize(sfSprite_getTexture(ent->sprite));
    float rotation = sfSprite_getRotation(ent->sprite);

    sfSprite_setOrigin(ent->sprite, (sfVector2f){text_size.x
    / 2.0f, text_size.y / 2.0f});
    sfRectangleShape_setSize(hitbox, (sfVector2f){width, height});
    sfRectangleShape_setOrigin(hitbox, (sfVector2f)
    {width / 2.0f, height / 2.0f});
    sfRectangleShape_setPosition(hitbox, sprite_pos);
    sfRectangleShape_setRotation(hitbox, rotation);
    sfRectangleShape_setFillColor(hitbox, sfTransparent);
    sfRectangleShape_setOutlineColor(hitbox, sfRed);
    sfRectangleShape_setOutlineThickness(hitbox, 1.0f);
    return hitbox;
}

void draw_plane_hitbox(sfRenderWindow* window, Entity* entity)
{
    float hitbox_width = 20.0f;
    float hitbox_height = 20.0f;
    sfRectangleShape* hitbox = set_hitbox(entity, hitbox_width, hitbox_height);

    sfRenderWindow_drawRectangleShape(window, hitbox, NULL);
    sfRectangleShape_destroy(hitbox);
}

void draw_tower_area(sfRenderWindow* window, Entity* ent, int greatest_side)
{
    sfCircleShape* area = sfCircleShape_create();
    float percentage_radius = ent->radius;
    float actual_radius = (percentage_radius / 100.0f) * greatest_side;
    sfVector2f size = (sfVector2f)
    {sfTexture_getSize(sfSprite_getTexture(ent->sprite)).x,
    sfTexture_getSize(sfSprite_getTexture(ent->sprite)).y};
    sfVector2f scale = sfSprite_getScale(ent->sprite);
    sfVector2f center;

    center.x = sfSprite_getPosition(ent->sprite).x +
    size.x * scale.x / 2.0f;
    center.y = sfSprite_getPosition(ent->sprite).y + size.y * scale.y / 2.0f;
    sfCircleShape_setRadius(area, actual_radius);
    sfCircleShape_setOrigin(area, (sfVector2f){actual_radius, actual_radius});
    sfCircleShape_setPosition(area, center);
    sfCircleShape_setFillColor(area, sfColor_fromRGBA(255, 255, 255, 128));
    sfCircleShape_setOutlineColor(area, sfBlue);
    sfCircleShape_setOutlineThickness(area, 1.0f);
    sfRenderWindow_drawCircleShape(window, area, NULL);
    sfCircleShape_destroy(area);
}

void render_timer(sfRenderWindow* window, Manager* manager)
{
    sfFloatRect text_rect;
    sfVector2u window_size;
    float x_position;
    float y_position;

    if (manager->timer_text != NULL) {
        text_rect = sfText_getGlobalBounds(manager->timer_text);
        window_size = sfRenderWindow_getSize(window);
        x_position = window_size.x - text_rect.width - 20.0f;
        y_position = 10.0f;
        sfText_setPosition(manager->timer_text,
        (sfVector2f){x_position, y_position});
        render_bg(window, x_position, y_position, &text_rect);
        sfRenderWindow_drawText(window, manager->timer_text, NULL);
    }
}

void render_bg(sfRenderWindow* win, float x, float y, sfFloatRect* text_rect)
{
    sfRectangleShape* background = sfRectangleShape_create();

    sfRectangleShape_setSize(background,
    (sfVector2f){text_rect->width + 40, text_rect->height + 40});
    sfRectangleShape_setFillColor(background, sfColor_fromRGBA(0, 0, 0, 150));
    sfRectangleShape_setPosition(background, (sfVector2f){x - 20, y - 20});
    sfRenderWindow_drawRectangleShape(win, background, NULL);
    sfRectangleShape_destroy(background);
}
