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

/** \brief INITIALIZES AN ARRAY STRUCTURE
 *
 * \param Profile[] HERE GOES THE STRUCTURE
 * \param int HERE GOES THE ARRAY SIZE
 * \return void
 *
 */
void init(Profile[], int);

/** \brief LOADS PREDEFINED PROFILES FOR A QUICK CODE CHECKING
 *
 * \param Profile* HERE GOES THE STRUCTURE
 * \param
 * \return void
 *
 */
void loadProfiles(Profile*);
void brief(Profile*, int);
void signup(Profile*, int);
void signdown(Profile*, int);
void modify(Profile*, int);
