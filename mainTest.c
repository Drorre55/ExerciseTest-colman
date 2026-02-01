#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

/* ---------- ex 1 ---------- */
void testInvert() {
    int A[N][N] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11,12,13,14,15},
        {16,17,18,19,20},
        {21,22,23,24,25}
    };

    printf("Matrix before invert:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%3d ", A[i][j]);
        printf("\n");
    }

    invert(A);

    printf("\nMatrix after invert:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%3d ", A[i][j]);
        printf("\n");
    }
}

/* ---------- ex 2 ---------- */
void testSortWords() {
    int size = 4;
    char** words = (char**)malloc(size * sizeof(char*));

    words[0] = _strdup("banana");
    words[1] = _strdup("apple");
    words[2] = _strdup("pear");
    words[3] = _strdup("orange");

    printf("\nWords before sort:\n");
    for (int i = 0; i < size; i++)
        printf("%s\n", words[i]);

    sortWords(&words, size);

    printf("\nWords after sort:\n");
    for (int i = 0; i < size; i++)
        printf("%s\n", words[i]);

    for (int i = 0; i < size; i++)
        free(words[i]);
    free(words);
}

/* ---------- ex 3 ---------- */
void testMovies() {
    country c;
    c._countryName = "Israel";
    c._moviesSet = NULL;
    c._moviesSetLen = 0;

    movie* m1 = (movie*)malloc(sizeof(movie));
    m1->_movieName = "Friends";
    m1->_seasonNum = 1;
    m1->_chapterNum = 1;
    m1->_lenInMinutes = 25;

    movie* m2 = (movie*)malloc(sizeof(movie));
    m2->_movieName = "Breaking Bad";
    m2->_seasonNum = 1;
    m2->_chapterNum = 1;
    m2->_lenInMinutes = 50;

    addMovieToCountry(&c, m1);
    //addMovieToCountry(&c, m2);

    movie* found = searchMovieByCountry(&c, "Friends");
    if (found)
        printf("\nMovie found: %s\n", found->_movieName);
    else
        printf("\nMovie not found\n");

    movie* allMovies[2] = { m1, m2 };
    int notAllowedSize = 0;

    movie** notAllowed =
        MoviesNotAllowedToCountry(&c, allMovies, 2, &notAllowedSize);

    printf("\nMovies not allowed in country:\n");
    for (int i = 0; i < notAllowedSize; i++)
        printf("%s\n", notAllowed[i]->_movieName);

    free(c._moviesSet);
    free(m1);
    free(m2);
    free(notAllowed);
}

/* ---------- ex 4 ---------- */
void testNumbers() {
    int num = 12345;

    printf("\nAlternatelySum(%d) = %d\n", num, AlternatelySum(num));
    printf("Is11Div(%d) = %d\n", num, Is11Div(num));

    printf("Is11Div(121) = %d\n", Is11Div(121));
}

int main() {
    testInvert();
    testSortWords();
    testMovies();
    testNumbers();

    return 0;
}
