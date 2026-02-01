/*  util.h  */


#ifndef __UTIL_H
#define __UTIL_H



#define N 5                 /* ex 1 */
#define SIZE 21             /* ex 3 */



void invert(int A[N][N]);   /* ex 1 */

/* ex 2  */

void sortWords(char*** words, int size);


/* ex 3 */

typedef struct Movie {
    char * _movieName;
    int _seasonNum;
    int _chapterNum;
    int _lenInMinutes;
}movie;

typedef struct Country {
    char * _countryName;
    movie ** _moviesSet;
    int _moviesSetLen;
}country;

typedef struct Member {
    char _memberName[SIZE];
    int _memberId;
    country * _memberCountry;
}member;

movie* searchMovieByCountry(country* c, char* moviesName);
int addMovieToCountry(country* c, movie* m);
movie** MoviesNotAllowedToCountry(country* c, movie** moviesPtr, int arrMoviesSize, int* arrSize);

/* ex 4 */

int AlternatelySum(int num);
int Is11Div(int num);







#endif /* __UTIL_H */
