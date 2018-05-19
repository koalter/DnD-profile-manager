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

/** \brief SHOWS A BRIEF LIST OF EVERY LOGGED CHARACTER
 *
 * \param Profile* STRUCTURE
 * \param int ARRAY SIZE
 * \return void
 *
 */
void brief(Profile*, int);

/** \brief SHOWS DETAILED INFO OF A SINGLE CHARACTER
 *
 * \param Profile* STRUCTURE
 * \param int ARRAY SIZE
 * \return void
 *
 */
void show(Profile*, int);

/** \brief SIGNS UP A NEW CHARACTER
 *      HP VALUE GETS DECIDED BY THE GM IN THIS VERSION
 * \param Profile* STRUCTURE
 * \param int ARRAY SIZE
 * \return void
 *
 */
void signup(Profile*, int);

void signdown(Profile*, int);
void modify(Profile*, int);
