#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  int x = 100;
  printf("value of x in parent process with pid %d is: %d\n", (int)getpid(), x);

  printf("forking!\n");
  int rc = fork();
  printf("Right after fork! \n");


  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    printf("Inside child process!\n");
    printf(
        "value of x in child process with pid %d before changing it is: %d\n",
        (int)getpid(), x);

    x += 5;

    printf("value of x in child process with pid %d after changing it is: %d\n",
           (int)getpid(), x);
  } else {
    printf("Inside parent process!\n");
    printf(
        "value of x in parent process with pid %d before changing it is: %d\n",
        (int)getpid(), x);

    x += 10;

    printf(
        "value of x in parent process with pid %d after changing it is: %d\n",
        (int)getpid(), x);
  }

  printf("value of x in in the end of process with pid %d is: %d\n", (int)getpid(), x);
  return 0;
}