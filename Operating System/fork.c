/**
* Fork programm. Demonstrating fork() system call
* @author: Ashish Gaikwad <ash.gkwd@gmail.com>
* @copy: No right reserved.
*/

#include <stdio.h>
#include <sys/types.h> // pid_t
#include <unistd.h> // fork()

int main () {
  pid_t p = fork();

  if (p == -1)
  {
    perror("fork failed");
  } else if (p == 0) {
    printf("Hello from child process\n");
    for (int i = 0; i < 5; ++i)
    {
      printf("Child counter: %d\n", i);
    }
  } else {
    printf("Hello from the parent process\n");
    for (int j = 0; j < 7; ++j)
    {
      printf("Parent counter: %d\n", j);
    }
  }
  return 0;
}