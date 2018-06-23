#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "ArrayList.h"

#define SIZE 10

int main()
{
    int option;

    ArrayList* pList = al_newArrayList();
    //Profile* character;

    do
    {
        printf("\t\t\t~~~D&D PROFILE MANAGER~~~\n");
        printf("\n1. Create new profile");
        printf("\n2. Delete profile");
        printf("\n3. Modify profile (change name)");
        printf("\n4. Show character's profile");
        printf("\n5. Show all profiles");
        printf("\n6. Export profiles");
        printf("\n7. Import profiles");
        printf("\n8. LOAD DEFAULT VALUES");
        printf("\n9. Exit\n");

        printf("\nINPUT AN OPTION: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                load_character(pList);
                break;
            case 8:
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
                option = 9;
                break;
        }

        system("pause");
        system("cls");
    }while(option != 9);

    return 0;
}
