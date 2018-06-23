#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#include "ArrayList.h"

#define ALIVE 1


Profile* new_character()
{
    void* character;

    character = (Profile*) malloc(sizeof(Profile));

    return character;
}

int load_character(ArrayList* pList)
{
    int returnAux = -1;
    char answer;
    Profile* character;

    int id;
    char name[50];
    int hp;
    char race[20];
    char gender;
    char class[20];

    if (pList != NULL)
    {
        character = new_character();
        /// BEGIN CHARACTER INFO
        id = pList->len(pList) + 1;
        setId(character,id);

        getString("Enter character's name: ",name);
        if(name == NULL)
        {
            return returnAux;
        }
        setName(character, name);

        gender = getChar("Enter character's gender [m/f]: ");
        if(gender != 'm' && gender != 'f' && gender != 'M' && gender != 'F')
        {
            return returnAux;
        }
        setGender(character, gender);

        getString("Input character's race: ",race);
        if(race == NULL)
        {
            return returnAux;
        }
        setRace(character, race);

        getString("Input character's class: ", class);
        if(class == NULL)
        {
            return returnAux;
        }
        setClass(character, class);

        hp = getInt("Enter character's hit points: ");
        setHP(character, hp);
        /// END CHARACTER INFO

        /// CONFIRMATION
        printf("\n\n%2s|%20s|%6s|%10s|%10s\n\n","ID","NAME","HEALTH","RACE","CLASS");
        show(character);

        answer = getChar("\nIS THIS INFORMATION CORRECT? [Y/N]: ");
        if (answer == 'y' || answer == 'Y')
        {
            character->status = ALIVE;
            pList->add(pList,character);

            returnAux = 0;
        }
        else
        {
            free(character);
        }
    } //if (character != NULL)

    return returnAux;
}

int loadHardCode(ArrayList* pList)
{
    int returnAux = -1;
    int i;
    Profile* character;

    int id[4] = {1,2,3,4};
    char name[4][20] = {"Asen Fullbrooke", "Branmir", "Nerifiel", "Dua Pein"};
    int maxHP[4] = {9, 7, 6, 7};
    char race[4][10] = {"Human","Elf","Elf","Human"};
    char gender[4] = {'M','M','F','F'};
    char classes[4][10] = {"Warrior","Wizard","Priest","Rogue"};
    //char align[4][20] = {"Lawful Good","Chaotic Neutral","Lawful Neutral","Neutral Evil"};

    if(pList != NULL)
    {
        for(i=0;i < 4;i++)
        {
            character = new_character();

            setId(character,id[i]);
            setName(character,name[i]);
            setHP(character,maxHP[i]);
            setRace(character,race[i]);
            setGender(character,gender[i]);
            setClass(character,classes[i]);
            character->status = ALIVE;

            pList->add(pList,character);
        }

        returnAux = 0;
    }

    return returnAux;
}

int show(Profile* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        printf("%2d|%20s|%3d/%2d|%10s|%10s",this->id,this->name,this->hp,this->maxHP,this->race,this->class);

        returnAux = 0;
    }
    return returnAux;
}

///setters
int setId(Profile* character, int id)
{
    int returnAux = -1;

    if(character != NULL)
    {
        character->id = id;

        returnAux = 0;
    }

    return returnAux;
}

int setName(Profile* character, char* name)
{
    int returnAux = -1;

    if(character != NULL)
    {
        strcpy(character->name, name);

        returnAux = 0;
    }

    return returnAux;
}

int setHP(Profile* character, int hp)
{
    int returnAux = -1;

    if(character != NULL)
    {
        character->maxHP = hp;
        character->hp = hp;

        returnAux = 0;
    }

    return returnAux;
}

int setRace(Profile* character, char* race)
{
    int returnAux = -1;

    if(character != NULL)
    {
        strcpy(character->race, race);

        returnAux = 0;
    }

    return returnAux;
}

int setGender(Profile* character, char gender)
{
    int returnAux = -1;

    if(character != NULL)
    {
        character->gender = gender;

        returnAux = 0;
    }

    return returnAux;
}

int setClass(Profile* character, char* class)
{
    int returnAux = -1;

    if(character != NULL)
    {
        strcpy(character->class, class);

        returnAux = 0;
    }

    return returnAux;
}


///getters
int getId(Profile* this)
{
    int id;

    if(this != NULL)
    {
        id = this->id;
    }

    return id;
}

char* getName(Profile* this)
{
    char* name;

    if(this != NULL)
    {
        name = this->name;
    }

    return name;
}

int getHP(Profile* this)
{
    int maxHP;

    if(this != NULL)
    {
        maxHP = this->maxHP;
    }

    return maxHP;
}

char* getRace(Profile* this)
{
    char* race;

    if(this != NULL)
    {
        race = this->race;
    }

    return race;
}

char getGender(Profile* this)
{
    char gender;

    if(this != NULL)
    {
        gender = this->gender;
    }

    return gender;
}

char* getClass(Profile* this)
{
    char* class;

    if(this != NULL)
    {
        class = this->class;
    }

    return class;
}


///input functions
int getInt(char *mensaje)
{
    int numero;
    char auxiliar[11];
    printf(mensaje);
    fflush(stdin);
    gets(auxiliar);
    numero = atoi(auxiliar);

    return numero;
}

char getChar(char* mensaje)
{
    char retorno;
    printf(mensaje);
    fflush(stdin);
    retorno = getchar();

    return retorno;
}

char* getString(char* mensaje, char retorno[])
{
    int i;
    printf(mensaje);
    fflush(stdin);
    gets(retorno);
    for(i=0;retorno[i] != '\0';i++)
    {
        if(retorno[i] >= '0' && retorno[i] <= '9')
        {
            retorno = NULL;
            break;
        }
    }
    return retorno;
}
