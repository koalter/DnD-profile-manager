#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

#define SIZE 10

int main()
{
    int option;
    int flag = 0;
    Profile character[SIZE];

    init(character,SIZE);
    do
    {
        printf("---D&D PROFILE MANAGER---\n");
        printf("\n1. Create new profile");
        printf("\n2. Delete profile");
        printf("\n3. Modify profile");
        printf("\n4. Show all profiles");
        printf("\n9. Exit\n");

        printf("\nINPUT AN OPTION: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:

                break;
            case 2:
                /**
                *   Espacio reservado para programar opcion
                */
            case 3:
                /**
                *   Espacio reservado para programar opcion
                */
            case 4:
                if(flag == 0)
                {
                    loadProfiles(character, SIZE);
                    brief(character, SIZE);
                    flag = 1;
                }
                else
                {
                    brief(character, SIZE);
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
