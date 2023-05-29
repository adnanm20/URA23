#include <algorithm>
#include <chrono>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>

void selectionsort(int *bg, int n) {
  for (int i = 0; i < n; i++) {
    int ind_min = i;
    for (int j = i + 1; j < n; j++) {
      if (bg[j] < bg[ind_min]) {
        ind_min = j;
      }
    }
    std::swap(bg[ind_min], bg[i]);
  }
}

void bubblesort(int *bg, int n) {
  for (int e = n; e > 1; e--) {
    bool swapped = false;
    for (int i = 0; i < e - 1; i++) {
      if (bg[i] > bg[i + 1]) {
        std::swap(bg[i], bg[i + 1]);
        swapped = true;
      }
    }
    if (!swapped)
      break;
  }
}

void insertionsort(int *bg, int n) {
  for (int i = 1; i < n; i++) {
    int j = i;
    int val = bg[i];
    for (; j > 0 && bg[j - 1] > val; j--) {
      bg[j] = bg[j - 1];
    }
    bg[j] = val;
  }
}

void insertionsort_var(int *bg, int n, int increment) {
  for (int i = increment; i < n; i += increment) {
    int j = i;
    int val = bg[i];
    for (; j >= increment && bg[j - increment] > val; j -= increment) {
      bg[j] = bg[j - increment];
    }
    bg[j] = val;
  }
}

void shellsort(int *bg, int n) {
  for (int increment = n / 2; increment >= 1; increment = increment / 2) {
    for (int i = 0; i < increment; i++) {
      insertionsort_var(bg + i, n - i, increment);
    }
  }
}

// helper - merges two sorted subarrays
void merge(int *array1, int array1len, int *array2, int array2len, int *dest) {
  int i1 = 0;
  int i2 = 0;

  while (i1 != array1len || i2 != array2len) {
    if (i1 == array1len) {
      *dest = array2[i2++];
      dest++;
    } else if (i2 == array2len) {
      *dest = array1[i1++];
      dest++;
    } else if (array1[i1] > array2[i2]) {
      *dest = array2[i2++];
      dest++;
    } else {
      *dest = array1[i1++];
      dest++;
    }
  }
}

// helper - recursive
void mergesort_r(int *bg, int *temp, int left, int right) {
  if (right - left < 2)
    return;
  int mid = (left + right) / 2;
  mergesort_r(bg, temp, left, mid);
  mergesort_r(bg, temp, mid, right);

  for (int i = left; i < right; ++i)
    temp[i] = bg[i];
  merge(temp + left, mid - left, temp + mid, right - mid, bg + left);
}

// stable
void mergesort(int *bg, int n) {
  auto temp = new int[n];
  mergesort_r(bg, temp, 0, n);
  delete[] temp;
}

// unstable
void quicksort(int *bg, int n) {
  if (n <= 1)
    return;
  int pivot_index = n / 2;
  std::swap(bg[pivot_index], bg[n - 1]);

  // Alternative
  int left = -1;
  int right = n - 1;
  do {
    while (bg[++left] < bg[n - 1])
      ;
    while ((left < right) && bg[n - 1] < bg[--right])
      ;
    std::swap(bg[left], bg[right]);
  } while (left < right);
  std::swap(bg[left], bg[n - 1]);

  quicksort(bg, left);
  quicksort(bg + left + 1, n - left - 1);
}

#define N 10000

int main(int argc, char *argv[]) {
  int v[N];
  int size = 0;

  while (std::cin >> v[size]) size++;
  std::cout << "Ucitano " << size << " brojeva" << std::endl;

  if(argc < 2) {
    std::cout << "give sorting algorithm as argument" << std::endl;
    return 1;
  }

  
  auto now = std::chrono::system_clock::now();
  if(strcmp(argv[1], "bubblesort") == 0) {
    now = std::chrono::system_clock::now();
    bubblesort(v, size);
  }
  else 
  if(strcmp(argv[1], "insertionsort") == 0) {
    now = std::chrono::system_clock::now();
    insertionsort(v, size);
  }
  else 
  if(strcmp(argv[1], "mergesort") == 0) {
    now = std::chrono::system_clock::now();
    mergesort(v, size);
  }
  else 
  if(strcmp(argv[1], "quicksort") == 0) {
    now = std::chrono::system_clock::now();
    quicksort(v, size);
  }
  else 
  if(strcmp(argv[1], "shellsort") == 0) {
    now = std::chrono::system_clock::now();
    shellsort(v, size);
  }
  else 
  if(strcmp(argv[1], "selectionsort") == 0) {
    now = std::chrono::system_clock::now();
    selectionsort(v, size);
  }
  else {
    std::cout << argv[1] << " sorting algorithm doesn't exist" << std::endl;
    return 2;
  }

  
  auto elapsed = std::chrono::system_clock::now() - now;
  std::cout << "" << elapsed.count()/1000 << "us" << std::endl;

  std::cout << std::is_sorted(v, v+size) << std::endl;
  return 0;
}
