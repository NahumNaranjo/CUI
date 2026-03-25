#include "cui.h"

void UI(){
    MenuOption options[] = {
        {"Option 1", "1"},
        {"Option 2", "2"}
    };
    size_t count;
    Menu* menu = createMenu("C User Interface", options, count);
    displayTitle(menu->title);
    char result = *displayMenu(menu);
    if(result == '1'){
        printf("Option 1 selected\n");
    } else{
        printf("Option 2 selected\n");
    }
}