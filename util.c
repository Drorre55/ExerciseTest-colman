#include "util.h"
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>


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
	return;
}

int addMovieToCountry(country* c, movie* m)
{
	return 0;
}

movie** MoviesNotAllowedToCountry(country* c, movie** moviesPtr, int arrMoviesSize, int* arrSize)
{
	return;
}

int AlternatelySum(int num)
{
	return 0;
}

int Is11Div(int num)
{
	return 0;
}
