#ifndef CUI_H
#define CUI_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <windows.h>
    #include <direct.h>
    #include "ariadne.h"

    typedef struct {
        char* label;
        char* returnValue;
    } MenuOption;

    typedef struct {
        char title[256];
        MenuOption* options;
        size_t optionCount;
    } Menu;

    static inline Menu* createMenu(char* title, MenuOption* options, size_t count){
        Menu* menu = (Menu*)malloc(sizeof(Menu));
        if(menu == NULL) return NULL;
        menu->title, title;
        menu->options = options;
        menu->optionCount = count;

        return menu;
    }

    static inline char* readInput(char* prompt, size_t maxl){
        static char buffer[512];
        printf("%s", prompt);
        if(!fgets(buffer, (int)maxl, stdin)){
            return NULL;
        }

        size_t len = strlen(buffer);
        if(len > 0 && buffer[len-1] == '\n'){
            buffer[len-1] = '\0';
        }

        return buffer;
    }

    static inline void* displayTitle(char* title){
        printf("\n%s\n", title);
        printf("================================\n");
    }

    static inline char* displayMenu(Menu* menu){
        for (size_t i = 0; i < menu->optionCount; i++){
            printf("%zu. %s\n", i+1, menu->options[i].label);
        }

        printf("================================\n");
        char* input = readInput("Select an option\n", 256);

        if(!input) return NULL;

        int choice = atoi(input);
        if(choice > 0 && choice <= (int)menu->optionCount){
            return menu->options[choice-1].returnValue;
        }
    
        printf("Invalid option. Try again.\n");
        return displayMenu(menu);
    }

    static inline int validateMenuOption(char* input, size_t optionCount){
        int choice = atoi(input);
        return(choice > 0 && choice <= (int) optionCount) ? choice : -1;
    }

    static inline void freeMenu(Menu* menu){
        if(menu) free(menu);
    }

#endif