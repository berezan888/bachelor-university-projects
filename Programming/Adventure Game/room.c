#include "room.h"
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct room* create_room(char *name, char *description) {
    if (name == NULL) {
        return NULL;
    }
    if (strlen(name) == 0) {
        return NULL;
    }

    if (description == NULL) {
        return NULL;
    }
    if (strlen(description) == 0) {
        return NULL;
    }
    struct room *room = calloc(1, sizeof(struct room));
    room->name = malloc(strlen(name) + 1);
    strcpy(room->name, name);
    room->description = malloc(strlen(description) + 1);
    strcpy(room->description, description);
    room->items = NULL;
    room->north = NULL;
    room->south = NULL;
    room->east = NULL;
    room->west = NULL;
    room->items = NULL;
    return room;
}

struct room* destroy_room(struct room* room){
    if(room == NULL){
        return NULL;
    }
    room->north = NULL;
    room->south = NULL;
    room->east = NULL;
    room->west = NULL;
    if(room->name != NULL){
        free(room->name);
    }
    if(room->description != NULL){
        free(room->description);
    }
    if(room->items != NULL){
        room->items = destroy_containers(room->items);
    }
    free(room);
    return NULL;
}//