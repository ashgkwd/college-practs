/**
* @author: Ashish Gaikwad <ash.gkwd@gmail.com>
* @copy: No rights reserved 2014 (MIT license)
* @description: Disk head scheduling algorithm. SCTF, FCFS, CSCAN.
*/

#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

int main () {
  int D, a, total_move=0, start, point, limit;
  std::vector<int> v;

  printf("Enter starting position of HEAD\n");
  scanf("%d", &start);
  v.push_back(start);

  printf("Enter max track limit\n");
  scanf("%d", &limit);

  printf("Enter total number of HEAD moves\n");
  scanf("%d", &D);

  printf("Enter %d HEAD moves\n", D);
  for (int i = 0; i < D; ++i) {
    scanf("%d", &a);
    v.push_back(a);
  }

  // FCFS
  printf("FCFS processing order:\n");
  for (int i = 0; i < D+1; ++i) {
    printf("%d \t", v[i]);
    if (i != D) {
      total_move += std::abs(v[i+1] - v[i]);
    }
  }

  printf("\nTotal HEAD move: %d\n", total_move);

  // CSCAN
  total_move = 0;
  printf("CSCAN processing order:\n");
  std::sort(v.begin(), v.end());
  v.insert(v.begin(), 0);
  v.push_back(limit);

  point = find(v.begin(), v.end(), start) - v.begin();

  if (v[point] - v[point-1] < v[point+1] - v[point]) {
    std::reverse(v.begin(), v.end());
    point = (v.size() - 1) - point;
  }

  for (int i = point; i < v.size(); ++i) {
    printf("%d\t", v[i]);
    if (i+1 != v.size()) {
      total_move += std::abs( v[i+1] - v[i] );
    }
  }

  total_move += std::abs( v.back() - v.front() );
  for (int i = 0; i < point; ++i) {
    printf("%d\t", v[i]);
    if (i+1 != point) {
      total_move += std::abs( v[i] - v[i+1] );
    }
  }

  printf("\nTotal HEAD move: %d\n", total_move);

  // SCTF
  total_move = 0;
  v.erase(v.begin());
  v.pop_back();
  std::sort(v.begin(), v.end());
  point = std::find(v.begin(), v.end(), start) - v.begin();

  printf("SCTF processing order:\n");
  for (int i = point; i < v.size(); ++i) {
    printf("%d\t", v[i]);

    if (i+1!=v.size()) {
      total_move += std::abs( v[i+1] - v[i] );
    }
  }

  total_move += std::abs( v.back() - v[point-1] );
  for (int i = point-1; i > 0; --i) {
    printf("%d\t", v[i]);
    total_move += std::abs( v[i] - v[i-1] );
  }
  printf("%d\n", v[0]); // as for loop don't show v[0]

  printf("Total HEAD move: %d\n", total_move);
}
