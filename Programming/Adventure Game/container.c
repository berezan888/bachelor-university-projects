#include "container.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <ctype.h>

int strcmp_lowercase(const char* s1, const char* s2)
{
    while(*s1 && *s2) {
        if(tolower(*s1) != tolower(*s2))
            return tolower(*s1) - tolower(*s2);
        s1++;
        s2++;
    }
    return tolower(*s1) - tolower(*s2);
}

struct container *create_container(struct container *first, enum container_type type, void *entry)
{
    struct container *container = malloc(sizeof(struct container));
    container->next = first;
    container->type = type;

    if (container->type == ROOM)
    {
        container->room = (struct room *)entry;
    }

    if (container->type == ITEM)
    {
        container->item = ( struct item *)entry;
    }

    if (container->type == COMMAND)
    {
        container->command = ( struct command *)entry;
    }

    if (container->type == TEXT)
    {
        container->text = (char *)entry;
    }

    return container;
}

struct container *destroy_containers(struct container *first)
{
    if (first == NULL)
        return NULL;

    struct container *current = first;

    while (current != NULL)
    {
        struct container *next = current->next;

        if (current->type == ITEM)
        {
            destroy_item(current->item);
            current->item = NULL;
        }

        if (current->type == COMMAND)
        {
            // printf("Destroying %s\n", current->command->name);
            destroy_command(current->command);
            current->command = NULL;
        }

        if (current->type == ROOM)
        {
            destroy_room(current->room);
            current->room = NULL;
        }

        if (current->type == TEXT)
        {
            free(current->text);
        }

        current = next;
    }

    return NULL;
}

void *get_from_container_by_name(struct container *first, const char *name)
{
    struct container *cursor = first;

    while(cursor != NULL){

        if (cursor->type == ITEM)
        {
            if(strcmp_lowercase(cursor->item->name, name) == 0)
                return cursor;
        }

        if (cursor->type == COMMAND)
        {
            if(strcmp_lowercase(cursor->command->name, name) == 0)
                return cursor;
        }

        if (cursor->type == ROOM)
        {
            if(strcmp_lowercase(cursor->room->name, name) == 0)
                return cursor;
        }

        if (cursor->type == TEXT)
        {
            if(strcmp_lowercase(cursor->text, name) == 0)
                return cursor;
        }

        cursor = cursor->next;
    }
    return NULL;
}

struct container* remove_container(struct container *first, void *entry){
    if(first == NULL || entry == NULL) return first;
    struct container *ptr, *ptr_prev;
    if(first->text == entry){
        ptr = first->next;
        free(first);
        return ptr;
    } else {
        ptr = first->next;
        ptr_prev = first;
        while(ptr != NULL){
            if(ptr->text == entry){
                ptr_prev->next = ptr->next;
                free(ptr);
                return first;
            }
            ptr_prev = ptr;
            ptr = ptr->next;
        }
    }
    return first;
}