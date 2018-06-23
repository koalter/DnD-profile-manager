#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

#include "ArrayList.h"

typedef struct
{
    int id;
    char* name;
    int hp;
    int maxHP;
    char* race;
    char gender;
    char* class;
    //char align[30];
    int status;
}Profile;

#endif // LIB_H_INCLUDED

Profile* init();
int load_character(ArrayList* pList);
int loadHardCode(ArrayList* pList);
int show(Profile*);

///setters
int setId(Profile*, int id);
int setName(Profile*, char* name);
int setHP(Profile*, int hp);
int setRace(Profile*, char* race);
int setGender(Profile*, char gender);
int setClass(Profile*, char* class);

///getters
int getId(Profile*);
char* getName(Profile*);
int getHP(Profile*);
char* getRace(Profile*);
char getGender(Profile*);
char* getClass(Profile*);

///input functions
int getInt(char *mensaje);
char getChar(char* mensaje);
char* getString(char* mensaje, char* retorno);
