#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#include "ArrayList.h"

#define ALIVE 1


Profile* new_character()
{
    Profile* character;

    character = (Profile*) malloc(sizeof(Profile));

    return character;
}

int load_character(ArrayList* pList)
{
    int returnAux = -1;
    int aux;
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

        aux = getString("Enter character's name: ",name);
        if(aux != 0)
        {
            printf("Invalid name!!\n");
            free(character);
            return returnAux;
        }
        setName(character, name);

        gender = getChar("Enter character's gender [m/f]: ");
        if(gender != 'm' && gender != 'f' && gender != 'M' && gender != 'F')
        {
            printf("Invalid gender!!\n");
            free(character);
            return returnAux;
        }
        setGender(character, gender);

        aux = getString("Input character's race: ",race);
        if(aux != 0)
        {
            printf("Invalid race!!\n");
            free(character);
            return returnAux;
        }
        setRace(character, race);

        aux = getString("Input character's class: ", class);
        if(aux != 0)
        {
            printf("Invalid class!!\n");
            free(character);
            return returnAux;
        }
        setClass(character, class);

        hp = getInt("Enter character's hit points: ");
        if(hp == 0)
        {
            printf("Invalid HP value!!\n");
            free(character);
            return returnAux;
        }
        setHP(character, hp);
        /// END CHARACTER INFO

        /// CONFIRMATION
        printf("\n\n%2s|%20s|%6s|%10s|%10s\n\n","ID","NAME","HEALTH","RACE","CLASS");
        show(character);

        answer = getChar("\nIS THIS INFORMATION CORRECT? [Y/N]: ");
        if (answer == 'y' || answer == 'Y')
        {
            character->status = ALIVE;
            al_add(pList,character);
            printf("Character succesfully added!!\n");

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
        pList->clear(pList);

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
        printf("%2d|%20s|%3d/%2d|%10s|%10s\n",this->id,this->name,this->hp,this->maxHP,this->race,this->class);

        returnAux = 0;
    }
    return returnAux;
}

int showAll(ArrayList* pList)
{
    int returnAux = -1;
    int length;
    int i;
    Profile* character;
    if(pList != NULL)
    {
        length = pList->len(pList);
        for(i=0;i < length;i++)
        {
            character = pList->get(pList,i);
            show(character);
        }
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

int setName(Profile* character, char name[])
{
    int returnAux = -1;

    if(character != NULL)
    {
        strcpy(character->name, name);
        //character->name = name;
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

int setRace(Profile* character, char race[])
{
    int returnAux = -1;

    if(character != NULL)
    {
        strcpy(character->race, race);
        //character->race = race;
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

int setClass(Profile* character, char class[])
{
    int returnAux = -1;

    if(character != NULL)
    {
        strcpy(character->class, class);
        //character->class = class;

        returnAux = 0;
    }

    return returnAux;
}


///getters
int getId(Profile* this)
{
    int id = NULL;

    if(this != NULL)
    {
        id = this->id;
    }

    return id;
}

char* getName(Profile* this)
{
    char* name = NULL;

    if(this != NULL)
    {
        name = this->name;
    }

    return name;
}

int getHP(Profile* this)
{
    int maxHP = NULL;

    if(this != NULL)
    {
        maxHP = this->maxHP;
    }

    return maxHP;
}

char* getRace(Profile* this)
{
    char* race = NULL;

    if(this != NULL)
    {
        race = this->race;
    }

    return race;
}

char getGender(Profile* this)
{
    char gender = NULL;

    if(this != NULL)
    {
        gender = this->gender;
    }

    return gender;
}

char* getClass(Profile* this)
{
    char* class = NULL;

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

int getString(char* mensaje, char this[])
{
    int returnAux = 0;
    int i;

    printf(mensaje);
    fflush(stdin);
    gets(this);
    for(i=0;this[i] != '\0';i++)
    {
        if(this[i] >= '0' && this[i] <= '9')
        {
            returnAux = -1;
            break;
        }
    }
    return returnAux;
}
