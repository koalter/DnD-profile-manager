#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define OPEN 0
#define ALIVE 1

typedef struct
{
    int id;
    char *name;
    int hp;
    int maxHP;
    char *race;
    char gender;
    char *classes;
    char *align;
    int status;
}Profile;

void init(Profile*, int);
void loadProfiles(Profile*, int);
void brief(Profile*, int);
void signup(Profile*, int);
void signdown(Profile*, int);
void modify(Profile*, int);

int main()
{
    int option;
    Profile character[SIZE];

    init(character,SIZE);
    do
    {
        printf("---D&D PROFILE MANAGER---\n");
        printf("\n1. CREATE NEW PROFILE");
        printf("\n2. DELETE PROFILE");
        printf("\n3. MODIFY PROFILE");
        printf("\n4. SHOW ALL PROFILES\n");
        printf("9. EXIT\n");

        printf("\nINPUT AN OPTION: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                loadProfiles(character, SIZE);
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
                brief(character, SIZE);
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

void init(Profile *character,int length)
{
    int i;

    if (character != NULL && length > 0)
    {
        for(i=0;i<length;i++)
        {
            character[i].id = 0;
            character[i].name = '\0';
            character[i].hp = 0;
            character[i].maxHP = 0;
            character[i].race = '\0';
            character[i].gender = '\0';
            character[i].classes = '\0';
            character[i].align = '\0';
            character[i].status = OPEN;
        }
    }
    else
    {
        printf("ERROR: STRUCTURE COULD NOT BE INITIALIZED\n");
    }

}

void loadProfiles(Profile *character,int length)
{
    int i;

    int id[4] = {1,2,3,4};
    char name[4][30] = {"Asen Fullbrooke", "Branmir", "Nerifiel", "Dua Pein"};
    int hp[4] = {8, 4, 4, 7};
    int maxHP[4] = {9, 10, 6, 7};
    char race[4][20] = {"Human","Dwarf", "Elf", "Human"};
    char gender[4] = {'M','M','F','F'};
    char classes[4][20] = {"Knight","Warrior","Wizard","Rogue"};
    char align[4][20] = {"Lawful Good","Chaotic Neutral","Lawful Neutral","Neutral Evil"};

    if (character != NULL && length > 0)
    {
        for(i=0;i<4;i++)
        {
            character[i].id = id[i];
            character[i].name = name[i];
            character[i].hp = hp[i];
            character[i].maxHP = maxHP[i];
            character[i].race = race[i];
            character[i].gender = gender[i];
            character[i].classes = classes[i];
            character[i].align = align[i];
            character[i].status = ALIVE;
        }

        printf("\nPROFILES LOADED\n");
    }
    else
    {
        printf("\nERROR: PROFILES COULD NOT BE LOADED\n");
    }
}

void brief(Profile *character,int length)
{
    int i;

    if (character != NULL && length > 0)
    {
        printf("\nID\tNAME\tHEALTH\tRACE\tCLASS\n");
        for(i=0;i<length;i++)
        {
            if(character[i].status != OPEN)
            {
                printf("\n%d\t%s\t%d/%d\t%s\t%s\n",
                       character[i].id,
                       character[i].name,
                       character[i].hp,
                       character[i].maxHP,
                       character[i].race,
                       character[i].classes);
            }
        }
    }
    else
    {
        printf("\nERROR: PROFILES COULD NOT BE LOADED\n");
    }
}
