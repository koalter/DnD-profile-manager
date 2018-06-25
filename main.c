#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "ArrayList.h"

#define SIZE 10

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
        //printf("\n2. Delete profile");
        //printf("\n3. Modify profile (change name)");
        printf("\n4. Show all profiles");
        //printf("\n6. Export profiles");
        //printf("\n7. Import profiles");
        printf("\n7. LOAD DEFAULT VALUES");
        printf("\n9. Exit\n");

        printf("\nINPUT AN OPTION: ");
        fflush(stdin);
        option = getchar();
        //scanf("%d", &option);

        switch(option)
        {
            case '1':
                load_character(pList);
                break;
            case '4':
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
