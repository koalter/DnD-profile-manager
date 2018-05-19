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
        printf("\n3. Modify profile (change name)");
        printf("\n4. Show character's profile");
        printf("\n5. Show all profiles");
        printf("\n9. Exit\n");

        printf("\nINPUT AN OPTION: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                signup(character,SIZE);
                flag = 1;
                break;
            case 2:
                signdown(character,SIZE);
                break;
            case 3:
                modify(character,SIZE);
                break;
            case 4:
                if(flag == 0)
                {
                    loadProfiles(character);
                    show(character, SIZE);
                    flag = 1;
                }
                else
                {
                    show(character, SIZE);
                }
                break;
            case 5:
                if(flag == 0)
                {
                    loadProfiles(character);
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
