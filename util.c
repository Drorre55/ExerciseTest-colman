/*  util.c */

/*
 Name: Dror Regev
 ID: 33333333
 */

#include "util.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/***   ex 1  ***/

void invert(int A[N][N])
{
    int i,j, tmp;
    
    for (i=0; i<(N+1)/2; i++)
        for (j=i+1; j<N-i-1; j++)
        {
            tmp=A[N-1-i][j];
            A[N-1-i][j]=A[i][j];
            A[i][j]=tmp;
            
            tmp=A[j][N-i-1];
            A[j][N-i-1]=A[j][i];
            A[j][i]=tmp;
        }
}


/***   ex 2  ***/


void sortWords(char*** words, int size) {
    int i = 0, j = 0;
    
    for (i = 0;i<size;i++) {
        for (j = 0;j<size - 1 - i;j++) {
            if (strcmp((*words)[j], (*words)[j + 1])>0) {
                char* temp = (*words)[j];
                (*words)[j] = (*words)[j + 1];
                (*words)[j + 1] = temp;
            }
        }
    }
}




/***   ex 3  ***/


movie* searchMovieByCountry(country* c, char* moviesName)
{
    int i;
    for (i = 0; i < c->_moviesSetLen; i++)
        if (strcmp(c->_moviesSet[i]->_movieName, moviesName) == 0)
            return c->_moviesSet[i];
    return NULL;
}


int addMovieToCountry(country* c, movie* m)
{
    movie* temp = searchMovieByCountry(c, m->_movieName);
    if (temp != NULL) return 1;
    c->_moviesSet = (movie**)realloc(sizeof(movie*),++(c->_moviesSetLen));
    if (!(c->_moviesSet)) return 0;
    c->_moviesSet[c->_moviesSetLen - 1] = m;
    return 0;
}


movie** MoviesNotAllowedToCountry(country* c, movie** moviesPtr, int arrMoviesSize, int* arrSize)
{
    int i;
    int k = 0;
    movie ** newArr = NULL;
    (*arrSize) = 0;
    for (i = 0; i < arrMoviesSize; i++)
        if (searchMovieByCountry(c, moviesPtr[i]->_movieName)==NULL)
            (*arrSize)++;
    newArr = (movie **)calloc(*arrSize, sizeof(movie *));
    if (!newArr) return NULL;
    for (i = 0; i < arrMoviesSize; i++)
        if (searchMovieByCountry(c, moviesPtr[i]->_movieName))
            newArr[k++] = moviesPtr[i];
    return newArr;
}



/***   ex 4  ***/



int AlternatelySum(int num)
{
    int x,y;
    if (num < 10)
        return num;
    if (num < 100)
        return num/10 - num%10;
    
    x = - (num/10)%10 + num%10;
    y = AlternatelySum(num/100);
    
    return x + y;
}



int Is11Div(int num)
{
    int x;
    if(num == 0){
        return 1;
    }
    if(num < 10){
        return 0;
    }
    
    x = AlternatelySum(num);
    x = (x<0)?-x:x; // absolute
    return Is11Div(x);
}

