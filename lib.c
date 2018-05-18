#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

#define OPEN 0
#define ALIVE 1

void init(Profile *character,int length)
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

void loadProfiles(Profile *character,int length)
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

    if (character != NULL && length > 0)
    {
        for(i=0;i<4;i++)
        {
            character[i].id = id[i];
            strcpy(character[i].name,name[i]);
            character[i].hp = hp[i];
            character[i].maxHP = maxHP[i];
            strcpy(character[i].race,race[i]);
            character[i].gender = gender[i];
            strcpy(character[i].classes,classes[i]);
            strcpy(character[i].align,align[i]);
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
        printf("\n%2s|%20s|%6s|%10s|%10s\n\n","ID","NAME","HEALTH","RACE","CLASS");
        for(i=0;i<length;i++)
        {
            if(character[i].status != OPEN)
            {
                printf("%2d|%20s|%3d/%2d|%10s|%10s\n",
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
