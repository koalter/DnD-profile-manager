#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

#define SIZE 10

int main()
{
    int option;
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
        printf("\n6. Export profiles");
        printf("\n7. Import profiles");
        printf("\n8. RESET TO DEFAULT VALUES");
        printf("\n9. Exit\n");

        printf("\nINPUT AN OPTION: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                signup(character,SIZE);
                break;
            case 2:
                signdown(character,SIZE);
                break;
            case 3:
                modify(character,SIZE);
                break;
            case 4:
                show(character, SIZE);
                break;
            case 5:
                brief(character, SIZE);
                break;
            case 6:
                sExport(character, SIZE);
                break;
            case 7:
                sImport(character, SIZE);
                break;
            case 8:
                init(character,SIZE);
                loadHardCode(character);
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
