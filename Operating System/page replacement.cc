/**
* @author: Ashish Gaikwad <ash.gkwd@gmail.com>
* @copy: No rights reserved 2014 (MIT license)
* @description: Page replacement algorithms LRU, FIFO.
*/
#include <cstdio>
#include <vector>

int main () {
  int P, a;
  const int PAGES = 3;
  std::vector<int> v;
  int pageFile[PAGES] = {-1};

  printf("Enter total number of pages\n");
  scanf("%d", &P);
  for (int i = 0; i < P; ++i) {
    scanf("%d", &a);
    v.push_back(a);
  }

  // First In First Out
  int toOut = 0, s = 0, faultsCout = 0;
  for (int i = 0; i < P; ++i) {
    int C = v[i];
    for (s = 0; s<PAGES; ++s) {
      if (pageFile[s]==C) {
        printf("%d : Hit\n", C);
        break;
      }
    }
    // If not Hit then
    if (s==PAGES) {
      printf("%d : Fault\n", C);
      faultsCout++;
      pageFile[toOut] = C;
      toOut = (toOut + 1) % PAGES;
    }
  }
  printf("Total Faults in FIFO: %d\n", faultsCout);

  // Least Recently Used
  // pageFile[0] is lru. Array will be sorted as per Hits.
  faultsCout = 0;
  // Reset pageFile
  for (int k = 0; k < PAGES; ++k) {
    pageFile[k] = -1;
  }

  for (int i = 0; i < P; ++i) {
    int C = v[i];
    for (s = 0; s<PAGES; ++s) {
      if (pageFile[s]==C) {
        printf("%d : Hit\n", C);
        // sort pageFile
        if (s!=PAGES-1) {
          for (int w = s+1; w < PAGES; ++w) {
            pageFile[w-1] = pageFile[w];
          }
          pageFile[PAGES-1] = C;
        }
        break;
      }
    }
    if (s==PAGES) {
      printf("%d : Fault\n", C);
      faultsCout++;
      for (int r = 1; r < PAGES; ++r) {
        pageFile[r-1] = pageFile[r];
      }
      pageFile[PAGES-1] = C;
    }
  }
  printf("Total Faults in LRU: %d\n", faultsCout);
}