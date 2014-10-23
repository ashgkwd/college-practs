/**
* @author: Ashish Gaikwad <ash.gkwd@gmail.com>
* @copy: All rights reserved 2014
* @description: CPU Scheduling algorithms like FCFS, SJF, Round Robin.
*/

#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>

class Process {
public:
  Process(std::string n, int a, int b) {
    name = n;
    arrival = a;
    burst = b;
  }
  std::string name;
  int arrival, burst, start, finish, tat, waiting;
};

void non_preemptive(std::vector<Process> v, int N) {
  int total_waiting = 0, total_tat = 0;

  // calculate WT, TAT using FCFS
  for (int i = 0; i < N; ++i)
  {
    Process& p = v[i];
    if (i == 0)
      p.start = p.arrival;
    else
      p.start = v[i-1].finish;

    p.finish = p.start + p.burst;
    p.tat = p.finish - p.arrival;
    p.waiting = p.start - p.arrival;
  }

  printf("Name\tArrival\tBurst\tStart\tFinish\tTurn Around\n");
  for (int i = 0; i < N; ++i)
  {
    Process& p = v[i];
    total_waiting += p.waiting;
    total_tat += p.tat;

    printf("%s \t %d \t %d \t %d \t %d \t %d\n",
      p.name.c_str(), p.arrival, p.burst, p.start, p.finish, p.tat);
  }

  printf("Average Waiting Time %f\n", (total_waiting*1.0)/N );
  printf("Average Turn Around Time %f\n", (total_tat*1.0)/N );
}

bool sortFCFS(Process i, Process j) {
  return i.arrival < j.arrival;
}

bool sortSJF(Process i, Process j) {
  return i.burst < j.burst;
}

int main () {
  std::vector<Process> v;
  int N, a, b;
  char s[100];

  printf("Enter total number of processes\n");
  scanf("%d", &N);
  printf("Enter Process Name, Arrival Time, Burst Time\n");
  for (int i = 0; i<N; i++) {
    scanf("%s%d%d", s, &a, &b);
    v.push_back(Process(s, a, b));
  }

  printf("FCFS:\n");
  std::sort(v.begin(), v.end(), sortFCFS);
  //for (auto k : v) printf("%s %d\n", k.name.c_str(), k.arrival);
  non_preemptive(v, N); // First Come First Serve

  printf("SJF:\n");
  std::sort(v.begin(), v.end(), sortSJF);
  //for (auto k : v) printf("%s %d\n", k.name.c_str(), k.burst);
  non_preemptive(v, N); // Shortest Job First
}
