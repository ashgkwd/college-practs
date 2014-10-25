/**
* @author: Ashish Gaikwad <ash.gkwd@gmail.com>
* @copy: All rights reserved 2014
* @description: Matrix (2D array) IO operations.
*/

#ifndef H_MATRIXIO
#define H_MATRIXIO 221

template <int N, int M>
int mprintf (int (& a)[N][M], int x = -1, int y = -1) {
  if (x == -1) x = N;
  if (y == -1) y = M;
  for (int i = 0; i < x; i++) {
    for (int j = 0; j< y; j++)
      printf("%d ", a[i][j]);
    printf("\n");
  }
}

template <int N, int M>
int mscanf (int (& a)[N][M], int x = -1, int y = -1) {
  if (x == -1) x = N;
  if (y == -1) y = M;
  for (int i = 0; i < x; i++)
    for (int j = 0; j< y; j++)
      scanf("%d", &a[i][j]);
}

#endif