#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

#define OPEN 0
#define ALIVE 1
#define DELETED -1

void init(Profile character[],int length)
{
    int i;

    if (character != NULL && length > 0)
    {
        for(i=0;i<length;i++)
        {
            character[i].id = 0;
            strcpy(character[i].name,"");
            character[i].hp = 0;
            character[i].maxHP = 0;
            strcpy(character[i].race,"");
            character[i].gender = '\0';
            strcpy(character[i].classes,"");
            strcpy(character[i].align,"");
            character[i].status = OPEN;
        }
    }
    else
    {
        printf("ERROR: STRUCTURE COULD NOT BE INITIALIZED\n");
    }

}

void loadProfiles(Profile *character)
{
    int i;

    int id[4] = {1,2,3,4};
    char name[4][30] = {"Asen Fullbrooke", "Branmir", "Nerifiel", "Dua Pein"};
    int hp[4] = {8, 4, 4, 7};
    int maxHP[4] = {9, 10, 6, 7};
    char race[4][30] = {"Human","Dwarf", "Elf", "Human"};
    char gender[4] = {'M','M','F','F'};
    char classes[4][30] = {"Knight","Warrior","Wizard","Rogue"};
    char align[4][30] = {"Lawful Good","Chaotic Neutral","Lawful Neutral","Neutral Evil"};

    if (character != NULL)
    {
        for(i=0;i<4;i++)
        {
            (character+i)->id = id[i];
            strcpy((character+i)->name,name[i]);
            (character+i)->hp = hp[i];
            (character+i)->maxHP = maxHP[i];
            strcpy((character+i)->race,race[i]);
            (character+i)->gender = gender[i];
            strcpy((character+i)->classes,classes[i]);
            strcpy((character+i)->align,align[i]);
            (character+i)->status = ALIVE;
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
        printf("\n%2s|%20s|%6s|%10s|%10s\n\n","ID","NAME","HEALTH","RACE","CLASS");
        for(i=0;i<length;i++)
        {
            if((character+i)->status != OPEN && (character+i)->status != DELETED)
            {
                printf("%2d|%20s|%3d/%2d|%10s|%10s\n",
                       (character+i)->id,
                       (character+i)->name,
                       (character+i)->hp,
                       (character+i)->maxHP,
                       (character+i)->race,
                       (character+i)->classes);
            }
        }
    }
    else
    {
        printf("\nERROR: PROFILES COULD NOT BE LOADED\n");
    }
}

void show(Profile *character,int length)
{
    int i;
    int index;
    int flag;

    if (character != NULL && length > 0)
    {
        brief(character,length);
        printf("\nEnter character's ID: ");
        scanf("%d", &i);
        index = i-1;
        for(flag=0;(character+index)->status == OPEN || (character+index)->status == DELETED;flag++)
        {
            printf("ERROR:Enter character's ID: ");
            scanf("%d", &i);
            index = i-1;
            if (flag == 2)
            {
                return;
            }
        }

        /// DISPLAY INFO
        printf("\n%s\n",(character+index)->name);
        printf("\nHit Points: %d/%d",(character+index)->hp,(character+index)->maxHP);
        printf("\nGender: %c",(character+index)->gender);
        printf("\nRace: \t%s",(character+index)->race);
        printf("\nClass: \t%s\n",(character+index)->classes);
        /// END DISPLAY
    }
    else
    {
        printf("\nERROR: PROFILES COULD NOT BE LOADED\n");
    }
}

void signup(Profile *character,int length)
{
    int i;
    int index;
    int flag;
    char answer;

    int id;
    char name[50];
    int hp;
    int maxHP;
    char race[30];
    char gender;
    char classes[30];

    if (character != NULL && length > 0)
    {
        for(i=0;i<length;i++)
        {
            if(character[i].status == OPEN)
            {
                index = i;
                break;
            }
        }
        //printf("%d\n", index); //index number

        /// BEGIN CHARACTER INFO
        id = index + 1;

        printf("\nEnter character's name: ");
        fflush(stdin);
        gets(name);

        printf("\nEnter character's gender [m/f]: ");
        fflush(stdin);
        scanf("%c",&gender);
        for(flag=0;gender != 'm' && gender != 'f' && gender != 'M' && gender != 'F';flag++)
        {
            printf("\nERROR:Enter character's gender [m/f]: ");
            fflush(stdin);
            scanf("%c",&gender);
            if (flag == 2)
            {
                return;
            }
        }

        printf("\nEnter character's race: ");
        fflush(stdin);
        gets(race);

        printf("\nEnter character's class: ");
        fflush(stdin);
        gets(classes);

        printf("\nEnter character's hit points: ");
        scanf("%d",&maxHP);
        hp = maxHP;
        /// END CHARACTER INFO

        /// CONFIRMATION
        printf("\n\n%2s|%20s|%6s|%10s|%10s\n\n","ID","NAME","HEALTH","RACE","CLASS");
        printf("%2d|%20s|%3d/%2d|%10s|%10s\n",id,name,hp,maxHP,race,classes);
        printf("\nIS THIS INFORMATION CORRECT? [Y/N]: ");
        fflush(stdin);
        scanf("%c", &answer);
        if (answer == 'y' || answer == 'Y')
        {
            (character+index)->id = id;
            strcpy((character+index)->name,name);
            (character+index)->hp = hp;
            (character+index)->maxHP = maxHP;
            strcpy((character+index)->race,race);
            (character+index)->gender = gender;
            strcpy((character+index)->classes,classes);
            (character+index)->status = ALIVE;
        }
    } //if (character != NULL && length > 0)

}

void signdown(Profile *character,int length)
{
    int i;
    int index;
    int flag;
    char answer;

    if (character != NULL && length > 0)
    {
        brief(character,length);
        printf("Enter character's ID: ");
        scanf("%d", &i);
        index = i-1;
        for(flag=0;(character+index)->status == OPEN || (character+index)->status == DELETED;flag++)
        {
            printf("ERROR:Enter character's ID: ");
            scanf("%d", &i);
            index = i-1;
            if (flag == 2)
            {
                return;
            }
        }

        /// DISPLAY INFO
        printf("\n%s\n",(character+index)->name);
        printf("\nCurrent Hit Points: %d/%d",(character+index)->hp,(character+index)->maxHP);
        printf("\nGender: \t%c",(character+index)->gender);
        printf("\nRace: \t%s",(character+index)->race);
        printf("\nClass: \t%s",(character+index)->classes);
        /// END DISPLAY

        /// CONFIRMATION
        printf("\nWARNING: THIS PROCESS CANNOT BE UNDONE. PRESS 'Y' TO CONTINUE AND DELETE THIS CHARACTER: ");
        fflush(stdin);
        scanf("%c", &answer);
        if (answer == 'y' || answer == 'Y')
        {
            /*
            (character+index)->id = 0;
            strcpy((character+index)->name,"");
            (character+index)->hp = 0;
            (character+index)->maxHP = 0;
            strcpy((character+index)->race,"");
            (character+index)->gender = "";
            strcpy((character+index)->classes,"");
            */
            (character+index)->status = DELETED;
        }
    }
    else
    {
        printf("\nERROR: PROFILES COULD NOT BE LOADED\n");
    }

}

void modify(Profile *character,int length)
{
    int i;
    int index;
    int flag;
    char answer;

    if (character != NULL && length > 0)
    {
        brief(character,length);
        printf("Enter character's ID: ");
        scanf("%d", &i);
        index = i-1;
        for(flag=0;(character+index)->status == OPEN || (character+index)->status == DELETED;flag++)
        {
            printf("ERROR:Enter character's ID: ");
            scanf("%d", &i);
            index = i-1;
            if (flag == 2)
            {
                return;
            }
        }

        /// DISPLAY INFO
        printf("\n%s\n",(character+index)->name);
        printf("\nCurrent Hit Points: %d/%d",(character+index)->hp,(character+index)->maxHP);
        printf("\nGender: \t%c",(character+index)->gender);
        printf("\nRace: \t%s",(character+index)->race);
        printf("\nClass: \t%s",(character+index)->classes);
        /// END DISPLAY

        /// CONFIRMATION
        printf("\nPRESS 'Y' TO PROCEED: ");
        fflush(stdin);
        scanf("%c", &answer);
        if (answer == 'y' || answer == 'Y')
        {
            printf("\nEnter character's new name: ");
            fflush(stdin);
            gets((character+index)->name);

            printf("\nName changed successfully!\n");
        }
    }
    else
    {
        printf("\nERROR: PROFILES COULD NOT BE LOADED\n");
    }
}
