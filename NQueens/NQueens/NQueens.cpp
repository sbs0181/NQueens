// NQueens.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

//Given that the ith queen is in row ri, can it be taken by the jth queen in row rj? (j>i)
bool QueenTest(int i, int ri, int j, int rj) {
	bool ans = true;
	if (ri == rj) {     //same row
		ans = false;
	} else if ((j - i) == (rj - ri)) {  //decreasing diagonal
		ans = false;
	} else if ((j - i) == (ri - rj)) {  //increasing diagonal
		ans = false;
	}
	return !ans;
}

bool CheckIfWorks(int arr[],int n) {
	bool so_far = true;
	for (int i = 1; i < n; i++) {
		for (int j = (i + 1); j < (n+1); j++) {
			if (QueenTest(i, arr[i - 1], j, arr[j - 1])) {
				so_far = false;
				goto label;
			}
		}
	}
label:
	return so_far;
}

void BruteForce() {
	int counter = 0;
	for (int c1 = 1; c1 <= 8; c1++) {
		for (int c2 = 1; c2 <= 8; c2++) {
			if (QueenTest(1, c1, 2, c2)) { continue; }
			for (int c3 = 1; c3 <= 8; c3++) {
				if ((QueenTest(1, c1, 3, c3) || QueenTest(2, c2, 3, c3))) { continue; }
				for (int c4 = 1; c4 <= 8; c4++) {
					if ((QueenTest(1, c1, 4, c4) || QueenTest(2, c2, 4, c4) || QueenTest(3, c3, 4, c4))) { continue; }
					for (int c5 = 1; c5 <= 8; c5++) {
						if ((QueenTest(1, c1, 5, c5) || QueenTest(2, c2, 5, c5) || QueenTest(3, c3, 5, c5) || QueenTest(4, c4, 5, c5))) { continue; }
						for (int c6 = 1; c6 <= 8; c6++) {
							if ((QueenTest(1, c1, 6, c6) || QueenTest(2, c2, 6, c6) || QueenTest(3, c3, 6, c6) || QueenTest(4, c4, 6, c6) || QueenTest(5, c5, 6, c6))) { continue; }
							for (int c7 = 1; c7 <= 8; c7++) {
								if ((QueenTest(1, c1, 7, c7) || QueenTest(2, c2, 7, c7) || QueenTest(3, c3, 7, c7) || QueenTest(4, c4, 7, c7) || QueenTest(5, c5, 7, c7) || QueenTest(6, c6, 7, c7))) { continue; }
								for (int c8 = 1; c8 <= 8; c8++) {
									if ((QueenTest(1, c1, 8, c8) || QueenTest(2, c2, 8, c8) || QueenTest(3, c3, 8, c8) || QueenTest(4, c4, 8, c8) || QueenTest(5, c5, 8, c8) || QueenTest(6, c6, 8, c8) || QueenTest(7, c7, 8, c8))) { continue; }
									counter++;
									//cout << counter << " : " << c1 << "," << c2 << "," << c3 << "," << c4 << "," << c5 << "," << c6 << "," << c7 << "," << c8 << "\n";

								}
							}
						}
					}
				}
			}
		}
	}
}
void PrintArr(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ",";
	}
	cout << "\n";
}
void PermuteMethod() {
	int n = 8;
	int counter = 0;
	int arr[] = { 1,2,3,4,5,6,7,8 };
	while (next_permutation(arr, arr + n)) {
		if (CheckIfWorks(arr, n)) {
			counter++;
			//cout << counter << " : ";
			//PrintArr(arr, n);
		}
	}
}

int main()
{
	clock_t start;
	start = clock();
	PermuteMethod();
	cout << "Time taken: " << (clock() - start) << "\n";
	start = clock();
	BruteForce();
	cout << "Time taken: " << (clock() - start) << "\n";
	system("pause");
    return 0;
}

