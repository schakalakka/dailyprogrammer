//
// Created by andreas on 5/6/16.
//

#include "permutationsandcombinations.h"

int factorial(int n) {
  if (n < 0) return 0;
  if (n == 0) return 1;
  int factorial = 1;
  for (int j = 0; j < n; j++) {
    factorial *= n - j;
  }
  return factorial;
}

int nchoosek(int n, int k) {
  if (n < k) {
    return 0;
  }
  int res = 1;
  for (int i = 0; i < k; i++) {
    res = res * (n - i) / (i + 1);
  }
  return res;
}

void findFactoradic(int N, int k, int *res) {
  int temp_fac;
  for (int i = 0; i < k; i++) {
    temp_fac = factorial(k - i - 1);
    res[i] = N / temp_fac;
    N %= temp_fac;
  }
}

void findCombinadics(int N, int k, int *res) {
  for (int i = 0; i < k; ++i) {
    res[i] = findCombinadicsCk(N, k - i);
    N -= nchoosek(res[i], k - i);
  }
}

int findCombinadicsCk(int N, int k) {
  int ck = k;
  while (N >= nchoosek(ck, k)) {
    ck++;
  }
  return ck - 1;

}

void permutation(int *arr, int n, int pos) {
  if (n < 1 || pos < 0 || factorial(n) <= pos) return;

  int unused[n];
  int qadicpos[n];

  for (int i = 0; i < n; i++) unused[i] = i;

  findFactoradic(pos, n, qadicpos);
  int counter_of_minus_ones;
  int counter_of_unused_values_to_qadicposi;
  for (int i = 0; i < n; i++) {
    counter_of_minus_ones = 0;
    counter_of_unused_values_to_qadicposi = 0;
    for (int j = 0; counter_of_unused_values_to_qadicposi <= qadicpos[i] && counter_of_minus_ones < n; j++) {
      if (unused[j] == -1) counter_of_minus_ones++;
      else counter_of_unused_values_to_qadicposi++;
    }

    arr[i] = unused[qadicpos[i] + counter_of_minus_ones];
    unused[qadicpos[i] + counter_of_minus_ones] = -1;
  }
}

void combination(int *arr, int n, int k, int pos) {
  findCombinadics(pos, k, arr);
}


int main() {
  int n = 25;
  int pos = 44245324432435235;
  int res[n];
  permutation(res, n, pos);
  for (int i = 0; i < n; i++) printf("%i ", res[i]);

  printf("\n");
  int k = 3;
  int res2[k];
  combination(res2, n, k, pos);
  for (int i = 0; i < k; i++) printf("%i ", res2[i]);
  return 0;
}