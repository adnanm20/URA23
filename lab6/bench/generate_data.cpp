// Preuzeto sa
// https://github.com/mariiaromaniuk/Sorting-Algorithms-Comparative-Analysis/blob/master/SortingAnalysis.cpp

/*
 Created by Mariia Romaniuk
 Sorting Analysis

 Program compares the relative performance of different sorting algorithms on
 datasets containing  integers. Ultimately, the data sorted in ascending order.
 Program tested on two different array sizes : 100 and 1000.
 Use the following random number distributions :
 a) Completely random
 b) Almost sorted in ascending order (about 90% of the items are in increasing
 order, 10% are random) c) Almost reversed -  same as b) but in reverse order d)
 Array is sorted except for the last 10% The following sorting algorithms are
 used:
 - Selection Sort
 - Insertion Sort
 - Heap Sort
 - Merge Sort
 - Quick Sort
 */

#include <cassert>
#include <ctime>
#include <iostream>

// functions to generate arrays with various number distributions
void allRandom(int a[], int size);
void randomLast(int a[], int size);
void almostSorted(int a[], int size);
void almostReversed(int a[], int size);

// function to generate an array with completely random number distribution
void allRandom(int a[], int size) {
  srand((unsigned)time(0));
  int random;
  for (int i = 0; i < size; i++) {
    random = (rand() % size) + 1;
    a[i] = random;
  }
}

// function to generate an almost sorted in ascending order array
// (about 90% of the items are in increasing order, 10% are random)
void almostSorted(int a[], int size) {
  srand((unsigned)time(0));

  for (int i = 0; i < size; i++)
    a[i] = i + 1;

  int rand1, rand2, i = 0;
  while (i < (size * .10)) {
    rand1 = (rand() % size) + 1;
    rand2 = (rand() % size) + 1;
    a[rand1] = rand2;
    i++;
  }
}

// function to generate an array with almost sorted reversed number distribution
// same as b) but in reverse order
void almostReversed(int a[], int size) {
  int n = 1;
  srand((unsigned)time(0));

  for (int i = size; i >= 0; i--)
    a[i] = n++;

  int rand1, rand2, i = 0;
  while (i < (size * .10)) {
    rand1 = (rand() % size) + 1;
    rand2 = (rand() % size) + 1;
    a[rand1] = rand2;
    i++;
  }
}

// function to generate an sorted array except for the last 10%
void randomLast(int a[], int size) {
  int m = size * .10; // calculate last 10% of integers
  int l = size - m;   // calculate first 90% of integers
  int n = 1;

  srand((unsigned)time(0));
  int random;

  for (int i = 0; i < l; i++)
    a[i] = n++;

  // calculate last 10% as random
  for (int i = 0; i < m; i++) {
    random = (rand() % 100) + 1;
    a[l] = random;
    l++;
  }
}

int main() {
  int n[10000];
  // allRandom(n, 10000);
  // almostReversed(n, 10000);
  almostSorted(n, 10000);
  for (auto &&a : n)
    std::cout << a << std::endl;
}
