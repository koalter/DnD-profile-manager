#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "ArrayList.h"

int main()
{
    char option;
    //int i;

    ArrayList* pList = al_newArrayList();
    //Profile* character;

    do
    {
        printf("\t\t\t~~~D&D PROFILE MANAGER~~~\n");
        printf("\n1. Create new profile");
        printf("\n2. Delete profile");
        printf("\n3. Show all profiles");
        //printf("\n4. Export profiles");
        //printf("\n5. Import profiles");
        printf("\n6. LOAD DEFAULT VALUES");
        printf("\n9. Exit\n");

        option = getChar("INPUT AN OPTION: ");

        switch(option)
        {
            case '1':
                if(load_character(pList) == 0)
                {
                    printf("Character successfully added!!\n");
                }
                else
                {
                    printf("Process could not be completed!!\n");
                }
                break;
            case '2':
                if(del_character(pList) == 0)
                {
                    printf("Character successfully deleted!!\n");
                }
                else
                {
                    printf("Process could not be completed!!\n");
                }
                break;
            case '3':
                printf("\n\n%2s|%20s|%6s|%10s|%10s\n\n","ID","NAME","HEALTH","RACE","CLASS");
                showAll(pList);
                break;
            case '7':
                if(loadHardCode(pList) == 0)
                {
                    printf("\nPROFILES LOADED\n");
                }
                else
                {
                    printf("\nERROR: PROFILES COULD NOT BE LOADED\n");
                }
                break;
            default:
                break;
        }

        system("pause");
        system("cls");
    }while(option != '9');

    return 0;
}
