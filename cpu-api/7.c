#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{
  int rc = fork();
  if (rc < 0)
  {
    fprintf(stderr, "Failed\n");
    exit(1);
  }
  else if (rc == 0)
  {
    printf("Hello from the child!, my pid is %d\n", (int)getpid());
    fflush(stdout);
    close(STDOUT_FILENO);
    printf("This is should not be printed cause standard output is closed.\n");
  }
  else
  {
    printf("Hello from the parent!, my pid is %d\n", (int)getpid());
  }
  return 0;
}