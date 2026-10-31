#include "container.h"
#include "item.h"
#include "command.h"
#include "room.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    struct room *room1 = create_room("Room 1", "Description 1");
    struct item *item1 = create_item("Item 1", "Description 1", 5);
    struct command *command1 = create_command("Command 1", "Description 1", "Pattern", 5);
    char *text1 = "Text 1";
    struct container *first = NULL;
    first = create_container(first, ROOM, room1);
    first = create_container(first, ITEM, item1);
    first = create_container(first, COMMAND, command1);
    first = create_container(first, TEXT, text1);
    destroy_containers(first);
    short bimbom = 321;
    short bimbom2= 73;
    short bimbom3 = 63;
    short bimbom4 = 23;
    short bimbom5 = 65;
    short bimbom6 = 4;
    short bimbom7 = 3;
    short bimbom8 = 9;
    short bimbom9 = 32;
    short bimbom10= bimbom - bimbom2 *1;
    short bimbom11 = bimbom3 + bimbom4+ bimbom5+ bimbom6*1;
    short bimbom12 = bimbom9 - bimbom8 + bimbom7;
    short bimbommm = bimbom10 + bimbom11 + bimbom12;
    if(bimbommm == 43){
        return 43;
    }
    return 0;
}
