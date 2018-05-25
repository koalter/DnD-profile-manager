#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

typedef struct
{
    int id;
    char name[30];
    int hp;
    int maxHP;
    int race;
    char gender;
    int classes;
    //char align[30];
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

/** \brief LOADS A HARDCODED STRUCTURE
 *
 * \param Profile* HERE GOES THE STRUCTURE
 * \param
 * \return void
 *
 */
void loadHardCode(Profile*);

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

/** \brief TAKES DOWN A CHARACTER'S PROFILE
 *
 * \param Profile* STRUCTURE
 * \param int ARRAZY SIZE
 * \return void
 *
 */
void signdown(Profile*, int);


/** \brief MODIFIES A CHARACTER'S NAME
 *
 * \param Profile* STRUCTURE
 * \param int ARRAY SIZE
 * \return void
 *
 */
void modify(Profile*, int);

/** \brief EXPORTS THE LOADED STRUCTURE INTO A BINARY FILE
 *
 * \param Profile* STRUCTURE
 * \param int SIZE OF THE STRUCTURE
 * \return void
 *
 */
void sExport(Profile*, int);

/** \brief IMPORTS A BINARY FILE INTO THE APP
 *
 * \param Profile*
 * \param int
 * \return void
 *
 */
void sImport(Profile*, int);

int switchRace();
int switchClass();
