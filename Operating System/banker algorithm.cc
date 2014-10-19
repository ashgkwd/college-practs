/**
* @author: Ashish Gaikwad <ash.gkwd@gmail.com>
* @copy: All rights reserved 2014
* @description: Bankers Algo. Process order is preserved.
*/

#include <cstdio>
#include "matrixio.h"

int main () {
  const int _ = 10;
  int claim[_][_] = {0};
  int allocated[_][_] = {0};
  int need[_][_] = {0};
  int available[_] = {0};
  int processes, resources;
  bool safe;

  printf("Enter number of processes and resources\n");
  scanf("%d%d", &processes, &resources);

  printf("Enter claim matrix %dx%d\n", processes, resources);
  mscanf(claim, processes, resources);

  printf("Enter allocated matrix %dx%d\n", processes, resources);
  mscanf(allocated, processes, resources);

  printf("Enter available resources (total %d)\n", resources);
  for (int i = 0; i < resources; i++)
    scanf("%d", &available[i]);

  // calculate need matrix
  for (int i = 0; i < processes; ++i)
    for (int j = 0; j < resources; ++j)
      need[i][j] = claim[i][j] - allocated[i][j];

  printf("Need matrix\n");
  mprintf(need, processes, resources);

  // Find state
  for (int i = 0, j; i < processes; i++) {
    for (j = 0; j< resources; j++)
      //safe = (need[i][j] <= available[j])? true: false;
    if (!(need[i][j] <= available[j])) {
      printf("Not Safe State [process %d, resources %d]\n", need[i][j], available[j]);
      return 0;
    }
  }

  printf("Safe State\n");
  return 0;
}