#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

#define WARRIOR 1
#define WIZARD 2
#define ROGUE 3
#define PRIEST 4

#define HUMAN 1
#define ELF 2

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
            character[i].race = 0;
            character[i].gender = '\0';
            character[i].classes = 0;
            //strcpy(character[i].align,"");
            character[i].status = OPEN;
        }
    }
    else
    {
        printf("ERROR: STRUCTURE COULD NOT BE INITIALIZED\n");
    }

}

void loadHardCode(Profile *character)
{
    int i;

    int id[4] = {1,2,3,4};
    char name[4][30] = {"Asen Fullbrooke", "Branmir", "Nerifiel", "Dua Pein"};
    int hp[4] = {8, 6, 4, 7};
    int maxHP[4] = {9, 7, 6, 7};
    int race[4] = {HUMAN,ELF,ELF,HUMAN};
    char gender[4] = {'M','M','F','F'};
    int classes[4] = {WARRIOR,WIZARD,PRIEST,ROGUE};
    //char align[4][30] = {"Lawful Good","Chaotic Neutral","Lawful Neutral","Neutral Evil"};

    if (character != NULL)
    {
        for(i=0;i<4;i++)
        {
            (character+i)->id = id[i];
            strcpy((character+i)->name,name[i]);
            (character+i)->hp = hp[i];
            (character+i)->maxHP = maxHP[i];
            (character+i)->race = race[i];
            (character+i)->gender = gender[i];
            (character+i)->classes = classes[i];
            //strcpy((character+i)->align,align[i]);
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
                printf("%2d|%20s|%3d/%2d",
                       (character+i)->id,
                       (character+i)->name,
                       (character+i)->hp,
                       (character+i)->maxHP);
                switch((character+i)->race)
                {
                    case HUMAN:
                        printf("|%10s","Human");
                        break;
                    case ELF:
                        printf("|%10s","Elf");
                        break;
                }
                switch((character+i)->classes)
                {
                    case WARRIOR:
                        printf("|%10s\n","Warrior");
                        break;
                    case WIZARD:
                        printf("|%10s\n","Wizard");
                        break;
                    case ROGUE:
                        printf("|%10s\n","Rogue");
                        break;
                    case PRIEST:
                        printf("|%10s\n","Priest");
                        break;
                }

            } //if((character+i)->status != OPEN && (character+i)->status != DELETED)
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
        printf("\nRace: \t");
        switch((character+index)->race)
                {
                    case HUMAN:
                        printf("Human");
                        break;
                    case ELF:
                        printf("Elf");
                        break;
                }
        printf("\nClass: \t");
        switch((character+index)->classes)
                {
                    case WARRIOR:
                        printf("Warrior\n");
                        break;
                    case WIZARD:
                        printf("Wizard\n");
                        break;
                    case ROGUE:
                        printf("Rogue\n");
                        break;
                    case PRIEST:
                        printf("Priest\n");
                        break;
                }
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
    int race;
    char gender;
    int classes;

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

        printf("\nInput character's race: \n");
        race = switchRace();
        for(flag=0;race < 1 || race > 2;flag++)
        {
            printf("\nERROR:Input character's race: ");
            race = switchRace();
            if (flag == 2)
            {
                return;
            }
        }

        printf("\nInput character's class: \n");
        classes = switchClass();
        for(flag=0;classes < 1 || classes > 4;flag++)
        {
            printf("\nERROR:Input character's class: ");
            classes = switchClass();
            if (flag == 2)
            {
                return;
            }
        }

        printf("\nEnter character's hit points: ");
        scanf("%d",&maxHP);
        hp = maxHP;
        /// END CHARACTER INFO

        /// CONFIRMATION
        printf("\n\n%2s|%20s|%6s|%10s|%10s\n\n","ID","NAME","HEALTH","RACE","CLASS");
        printf("%2d|%20s|%3d/%2d",id,name,hp,maxHP);
        switch(race)
        {
            case HUMAN:
                printf("|%10s","Human");
                break;
            case ELF:
                printf("|%10s","Elf");
                break;
        }
        switch(classes)
        {
            case WARRIOR:
                printf("|%10s\n","Warrior");
                break;
            case WIZARD:
                printf("|%10s\n","Wizard");
                break;
            case ROGUE:
                printf("|%10s\n","Rogue");
                break;
            case PRIEST:
                printf("|%10s\n","Priest");
                break;
        }
        printf("\nIS THIS INFORMATION CORRECT? [Y/N]: ");
        fflush(stdin);
        scanf("%c", &answer);
        if (answer == 'y' || answer == 'Y')
        {
            (character+index)->id = id;
            strcpy((character+index)->name,name);
            (character+index)->hp = hp;
            (character+index)->maxHP = maxHP;
            (character+index)->race = race;
            (character+index)->gender = gender;
            (character+index)->classes = classes;
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
        printf("\nGender: %c",(character+index)->gender);
        printf("\nRace: \t");
        switch((character+index)->race)
                {
                    case HUMAN:
                        printf("Human");
                        break;
                    case ELF:
                        printf("Elf");
                        break;
                }
        printf("\nClass: \t");
        switch((character+index)->classes)
                {
                    case WARRIOR:
                        printf("Warrior\n");
                        break;
                    case WIZARD:
                        printf("Wizard\n");
                        break;
                    case ROGUE:
                        printf("Rogue\n");
                        break;
                    case PRIEST:
                        printf("Priest\n");
                        break;
                }
        /// END DISPLAY

        /// CONFIRMATION
        printf("\nWARNING: THIS PROCESS CANNOT BE UNDONE.\nPRESS 'Y' TO CONTINUE AND DELETE THIS CHARACTER: ");
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
            */ /// RESERVED FOR EXTENDED OPTIONS
            (character+index)->status = OPEN;//DELETED;
            printf("CHARACTER DELETED!\n");
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
        printf("\nGender: %c",(character+index)->gender);
        printf("\nRace: \t");
        switch((character+index)->race)
                {
                    case HUMAN:
                        printf("Human");
                        break;
                    case ELF:
                        printf("Elf");
                        break;
                }
        printf("\nClass: \t");
        switch((character+index)->classes)
                {
                    case WARRIOR:
                        printf("Warrior\n");
                        break;
                    case WIZARD:
                        printf("Wizard\n");
                        break;
                    case ROGUE:
                        printf("Rogue\n");
                        break;
                    case PRIEST:
                        printf("Priest\n");
                        break;
                }
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

void sExport(Profile *character, int size)
{
    FILE *fchar;

    fchar = fopen("Profiles.dat","wb");
    if(fchar != NULL)
    {
        fwrite(character,sizeof(Profile),size,fchar);
        fclose(fchar);

        brief(character,size);
    }
    else
    {
        printf("\nUNABLE TO LOAD FILE!\n");
    }

}

void sImport(Profile *character, int size)
{
    FILE *fchar;

    fchar = fopen("Profiles.dat","rb");
    if(fchar != NULL)
    {
        fread(character,sizeof(Profile),size,fchar);
        fclose(fchar);

        brief(character,size);
    }
    else
    {
        printf("\nUNABLE TO LOAD FILE!\n");
    }
}

int switchRace()
{
    int aux;
    printf("1. Human\n");
    printf("2. Elf\n\n");
    scanf("%d",&aux);
    return aux;
}

int switchClass()
{
    int aux;
    printf("1. Warrior\n");
    printf("2. Wizard\n");
    printf("3. Rogue\n");
    printf("4. Priest\n\n");
    scanf("%d",&aux);
    return aux;
}
