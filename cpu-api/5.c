#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
  printf("I am the parent!\n");
  fflush(stdout);
  int rc = fork();

  if (rc < 0)
  {
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if (rc == 0)
  {
    printf("Hello from the child!, my pid is %d\n", (int)getpid());
    
    // Wait return value: On success, returns the process ID of the terminated child; on failure, -1 is returned.
    printf("Inside the child process, going to wait!\n");
    int valueOfWait = wait(NULL);
    printf("Value of wait in child is %d!\n", valueOfWait);
  }
  else
  {
    printf("Inside the parent process, going to wait!\n");
    int valueOfWait = wait(NULL);
    printf("Value of wait in parent is %d, which is the child process id!\n", valueOfWait);
  }

  return 0;
}