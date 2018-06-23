#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"

// funciones privadas
int resizeUp(ArrayList* this);
int resizeDown(ArrayList* this);
int expand(ArrayList* this,int index);
int contract(ArrayList* this,int index);

#define AL_INCREMENT      10
#define AL_INITIAL_VALUE  10
//___________________

/** \brief Allocate a new arrayList with AL_INITIAL_VALUE elements.
 * \param void
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new arrayList) if ok
 */
ArrayList* al_newArrayList(void)
{
    ArrayList* this;
    ArrayList* returnAux = NULL;
    void* pElements;
    this = (ArrayList *)malloc(sizeof(ArrayList));

    if(this != NULL)
    {
        pElements = malloc(sizeof(void *)*AL_INITIAL_VALUE );
        if(pElements != NULL)
        {
            this->size=0;
            this->pElements=pElements;
            this->reservedSize=AL_INITIAL_VALUE;
            this->add=al_add;
            this->len=al_len;
            this->set=al_set;
            this->remove=al_remove;
            this->clear=al_clear;
            this->clone=al_clone;
            this->get=al_get;
            this->contains=al_contains;
            this->push=al_push;
            this->indexOf=al_indexOf;
            this->isEmpty=al_isEmpty;
            this->pop=al_pop;
            this->subList=al_subList;
            this->containsAll=al_containsAll;
            this->deleteArrayList = al_deleteArrayList;
            this->sort = al_sort;
            returnAux = this;
        }
        else
        {
            free(this);
        }
    }

    return returnAux;
}


/** \brief  Add an element to arrayList and if is
 *          nessesary resize the array
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (0) if Ok
 *
 */
int al_add(ArrayList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL && pElement != NULL)
    {
        if(this->size == this->reservedSize)
        {
            resizeUp(this);
        }

        this->pElements[this->size] = pElement;
        this->size++;
        returnAux = 0;

    }


    return returnAux;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Ok
 *
 */
int al_deleteArrayList(ArrayList* this)
{
    int returnAux = -1;

    if(this != NULL) // if this exists
    {
        free(this->pElements); // take the pElements array and delete it from memory
        free(this);// then take this and delete it too from memory
        returnAux = 0;// if this succeeds, return 0
    }
    // else, if it doesn't (NULL)...

    return returnAux;// ...return -1;
}

/** \brief  Returns the size of arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return length of array or (-1) if Error [pList is NULL pointer]
 *
 */
int al_len(ArrayList* this)
{
    int returnAux = -1;

    if(this != NULL) //if this exists
    {
        returnAux = this->size;//show me the array size
    }

    return returnAux;
}


/** \brief  Get an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
void* al_get(ArrayList* this, int index)
{
    void* returnAux = NULL;

    if(this != NULL && (index <= al_len(this) && index >= 0)) // if this exists and we check a valid index in the list...
    {
        returnAux = this->pElements[index]; // return the pointer of that element...
    }

    return returnAux;
}


/** \brief  Find if pList contains at least one element pElement
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found a element
 *                  - ( 1) if this list contains at least one element pElement
 *
 */
int al_contains(ArrayList* this, void* pElement)
{
    int returnAux = -1;
    int index;

    if(this != NULL && pElement != NULL) // if the ArrayList and pElement exist..
    {
        returnAux = 0;
        for(index=0;index < al_len(this);index++)// check the ArrayList...
        {
            if(pElement == this->pElements[index]) // and check if this ArrayList contains pElement
            {
                returnAux++; // +1 if it found it...
                break;       // (we only need to check if there's at least one, so we break after)
            }
            // else, if it did not find pElement contained, it stays 0
        }
    }

    return returnAux;
}


/** \brief  Set a element in pList at index position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *
 */
int al_set(ArrayList* this, int index,void* pElement)
{
    int returnAux = -1;

    if((this != NULL && pElement != NULL) && (index < al_len(this) && index >= 0))
    {
        this->pElements[index] = pElement;// insert pElement in this->pElements[index]
        returnAux = 0;
    }

    return returnAux;
}


/** \brief  Remove an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_remove(ArrayList* this,int index)
{
    int returnAux = -1;
    int i;

    if(this != NULL && (index < al_len(this) && index >= 0))
    {
        for(i=index;i < al_len(this);i++)// Remove an element by index and shrink the pElements list
        {
            this->pElements[i] = this->pElements[i+1];
        }
        this->pElements[i] = NULL;
        this->size--;

        returnAux = 0;
    }

    return returnAux;
}



/** \brief Removes all of the elements from this list
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                  - ( 0) if Ok
 */
int al_clear(ArrayList* this)
{
    int returnAux = -1;
    void** pElement;

    if(this != NULL)
    {
        this->size = 0;

        pElement = (void**)realloc(this->pElements,sizeof(void *) * AL_INITIAL_VALUE);
        this->pElements = pElement;

        returnAux = this->size;
    }

    return returnAux;
}



/** \brief Returns an array containing all of the elements in this list in proper sequence
 * \param pList ArrayList* Pointer to arrayList
 * \return ArrayList* Return  (NULL) if Error [pList is NULL pointer]
 *                          - (New array) if Ok
 */
ArrayList* al_clone(ArrayList* this)
{
    ArrayList* returnAux = NULL;
    int i;

    if(this != NULL)
    {
        returnAux = al_newArrayList();

        returnAux->size = al_len(this);
        returnAux->reservedSize = this->reservedSize;
        for(i=0;i<al_len(this);i++)
        {
            returnAux->pElements[i] = al_get(this,i);
        }
    }

    return returnAux;
}




/** \brief Inserts the element at the specified position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_push(ArrayList* this, int index, void* pElement)
{
    int returnAux = -1;
    int i;

    if((this != NULL && pElement != NULL) && (index <= al_len(this) && index >= 0))
    {
        if(index == al_len(this))
        {
            al_add(this,pElement);
        }
        else
        {
            if(this->size == this->reservedSize)
            {
                resizeUp(this);
            }

            for(i = al_len(this);i > index;i--)
            {
                al_set(this,i,this->pElements[i-1]);
            }

            al_set(this,index,pElement);
            this->size++;
        }

        returnAux = 0;
    }

    return returnAux;
}



/** \brief Returns the index of the first occurrence of the specified element
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (index to element) if Ok
 */
int al_indexOf(ArrayList* this, void* pElement)
{
    int returnAux = -1;
    int i;

    if(this != NULL && pElement != NULL)
    {
        for(i=0;i < al_len(this);i++)
        {
            if(pElement == this->pElements[i])
            {
                returnAux = i;
                break;
            }
        }
    }

    return returnAux;
}



/** \brief Returns true if this list contains no elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
int al_isEmpty(ArrayList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        if(al_len(this) == 0)
        {
            returnAux = 1;
        }
        else
        {
            returnAux = 0;
        }

    }

    return returnAux;
}




/** \brief Remove the item at the given position in the list, and return it.
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid index]
 *                  - ( element pointer) if Ok
 */
void* al_pop(ArrayList* this,int index)
{
    void* returnAux = NULL;

    if(this != NULL && (index <= al_len(this) && index >= 0))
    {
        returnAux = al_get(this,index);

        al_remove(this, index);
    }

    return returnAux;
}


/** \brief Returns a new arrayList with a portion of pList between the specified
 *         fromIndex, inclusive, and toIndex, exclusive.
 * \param pList ArrayList* Pointer to arrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid 'from' or invalid 'to']
 *                  - ( pointer to new array) if Ok
 */
ArrayList* al_subList(ArrayList* this,int from,int to)
{
    void* returnAux = NULL;
    void** pElement;
    int i;


    if(this != NULL && (from >= 0 && from < to) && (to <= al_len(this) && to > from))
    {
        returnAux = al_newArrayList();

        for(i=from;i < to;i++)
        {
            pElement = al_get(this,i);
            al_add(returnAux,pElement);
        }
    }

    return returnAux ;
}





/** \brief Returns true if pList list contains all of the elements of pList2
 * \param pList ArrayList* Pointer to arrayList
 * \param pList2 ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList or pList2 are NULL pointer]
 *                  - (0) if Not contains All - (1) if is contains All
 */
int al_containsAll(ArrayList* this,ArrayList* this2)
{
    int returnAux = -1;
    int contains = 0;
    int i;
    int j;

    if(this != NULL && this2 != NULL)
    {
        returnAux = 0;

        if(al_len(this) == al_len(this2))
        {
            for(i=0;i < al_len(this);i++)
            {
                for(j=0;j < al_len(this2);j++)
                {
                    if(this->pElements[i] == this2->pElements[j])
                    {
                        contains++;
                        break;
                    }

                }//for(j=0;j < al_len(this2);j++)

            }//for(i=0;i < al_len(this);i++)

            if(contains == al_len(this))
            {
                returnAux = 1;
            }

        }

    }

    return returnAux;
}

/** \brief Sorts objects of list, use compare pFunc
 * \param pList ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer]
 *                  - (0) if ok
 */
int al_sort(ArrayList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux = -1;
    int i;
    int j;
    void* pAux;

    if(this != NULL && *pFunc != NULL && (order == 0 || order == 1))
    {
        for(i=0;i < al_len(this) - 1;i++)
        {
            for(j=i+1;j < al_len(this);j++)
            {
                if(pFunc(this->pElements[i],this->pElements[j]) == order)
                {
                    pAux = this->pElements[i];
                    this->pElements[i] = this->pElements[j];
                    this->pElements[j] = pAux;
                }
            }
        }

        returnAux = 0;
    }

    return returnAux;
}


/** \brief Increment the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeUp(ArrayList* this)
{
    int returnAux = -1;
    void** auxiliar;

    if(this != NULL)
    {
        auxiliar = (void**) realloc(this->pElements, sizeof(void*) * (this->reservedSize + AL_INCREMENT));
        if(auxiliar != NULL)
        {
            this->pElements = auxiliar;
            this->reservedSize = this->reservedSize + AL_INCREMENT;
            returnAux = 0;
        }
        else
        {
            free(auxiliar);
        }
    }

    return returnAux;

}

int resizeDown(ArrayList* this)
{
    int returnAux = -1;
    void** auxiliar;

    if(this != NULL)
    {
        auxiliar = (void**) realloc(this->pElements, sizeof(void*) * (this->reservedSize - AL_INCREMENT));
        if(auxiliar != NULL)
        {
            this->pElements = auxiliar;
            this->reservedSize = this->reservedSize + AL_INCREMENT;
            returnAux = 0;
        }
        else
        {
            free(auxiliar);
        }
    }

    return returnAux;

}




/** \brief  Expand an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* this,int index)
{
    int returnAux = -1;

    return returnAux;
}

/** \brief  Contract an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* this,int index)
{
    int returnAux = -1;

    return returnAux;
}
