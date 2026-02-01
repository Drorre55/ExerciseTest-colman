#include "util.h"
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


/*
Student Name: Dror Regev
ID: 00000000
*/

void invertRow(int A[N][N], int row) {
	int maxIdx = N - 1;
	int mainCrossIdx = row;
	int secondaryCrossIdx = maxIdx - row;

	// unvert row from the outside of the main and secondary crosses
	int closestCrossIdx = mainCrossIdx <= secondaryCrossIdx ? mainCrossIdx : secondaryCrossIdx;
	for (int i = 0; i < closestCrossIdx; i++) {
			int leftSideSwitch = A[row][i];
			int rightSideSwitch = A[row][maxIdx - i];

			A[row][i] = rightSideSwitch;
			A[row][maxIdx - i] = leftSideSwitch;
	}
}

void invertCol(int A[N][N], int col) {
	int maxIdx = N - 1;
	int mainCrossIdx = col;
	int secondaryCrossIdx = maxIdx - col;

	int closestCrossIdx = mainCrossIdx <= secondaryCrossIdx ? mainCrossIdx : secondaryCrossIdx;
	// unvert column from the outside of the main and secondary crosses
	for (int i = 0; i < closestCrossIdx; i++) {
		int upSideSwitch = A[i][col];
		int downSideSwitch = A[maxIdx - i][col];

		A[i][col] = downSideSwitch;
		A[maxIdx - i][col] = upSideSwitch;
	}
}

void invert(int A[N][N])
{
	for (int j = 0; j < N; j++) {
		invertRow(A, j);
		invertCol(A, j);
	}
}

void moveFromEndToStartSlice(char*** words, int startIdx, int endIdx, bool includeStart) {
	char** myWords = *words;
	char* currentWord = myWords[endIdx];
	
	int stopIdx = includeStart ? startIdx - 1 : startIdx;
	for (int q = endIdx - 1; q > stopIdx; q--) {
		myWords[q + 1] = myWords[q];
	}
	myWords[stopIdx + 1] = currentWord;
}

void sortWords(char*** words, int size)
{
	char** myWords = *words;
	for (int i = 1; i < size; i++) {
		char* currentWord = myWords[i];

		for (int j = i - 1; j >= 0; j--) {
			char* previousWord = myWords[j];

			if (strcmp(currentWord, previousWord) > 0) {
				moveFromEndToStartSlice(&myWords, j, i, false);
				break;
			}
			else if (j == 0) {
				moveFromEndToStartSlice(&myWords, j, i, true);
			}
		}
	}
}

movie* searchMovieByCountry(country* c, char* moviesName)
{
	for (int i = 0; i < c->_moviesSetLen; i++) {
		movie* currentMovie = c->_moviesSet[i];
		if (strcmp(currentMovie->_movieName, moviesName) == 0) {
			return currentMovie;
		}
	}
	return NULL;
}

int addMovieToCountry(country* c, movie* m)
{
	if (searchMovieByCountry(c, m) != NULL) return 1;

	movie** tempMoviesSet = realloc(c->_moviesSet, (c->_moviesSetLen + 1) * sizeof * tempMoviesSet);
	if (tempMoviesSet == NULL) {
		printf("problem with malloc. couldn't add movie to country");
		return 0;
	}
	c->_moviesSet = tempMoviesSet;
	c->_moviesSet[c->_moviesSetLen] = m;
	
	c->_moviesSetLen++;

	return 1;
}

movie** MoviesNotAllowedToCountry(country* c, movie** moviesPtr, int arrMoviesSize, int* arrSize)
{
	movie** notAllowedMovies = NULL;
	*arrSize = 0;

	for (int i = 0; i < arrMoviesSize; i++) {
		movie* currentMovie = moviesPtr[i];

		if (searchMovieByCountry(c, currentMovie->_movieName) == NULL) {
			movie** tempNotAllowedMovies = realloc(notAllowedMovies, (*arrSize + 1) * sizeof * tempNotAllowedMovies);
			if (tempNotAllowedMovies == NULL) {
				printf("problem with realloc. couldn't get movies not allowed in country");
				return NULL;
			}
			notAllowedMovies = tempNotAllowedMovies;

			notAllowedMovies[*arrSize] = currentMovie;
			(*arrSize)++;
		}
	}
	return notAllowedMovies;
}

int AlternatelySum(int num)
{
	return 0;
}

int Is11Div(int num)
{
	return 0;
}
