#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

typedef struct
{
    int id;
    char name[30];
    int hp;
    int maxHP;
    char race[30];
    char gender;
    char classes[30];
    char align[30];
    int status;
}Profile;

#endif // LIB_H_INCLUDED

void init(Profile*, int);
void loadProfiles(Profile*, int);
void brief(Profile*, int);
void signup(Profile*, int);
void signdown(Profile*, int);
void modify(Profile*, int);
