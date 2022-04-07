#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
  int rc = fork();
  if (rc < 0)
  {
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if (rc == 0)
  {
    printf("Inside child process!, going to execute ls!\n");

    char *my_args[2];
    my_args[0] = strdup("ls");
    my_args[1] = NULL;

    fflush(stdout);
    execvp(my_args[0], my_args);
    printf("this shouldn't print out\n");
  }
  else
  {
    printf("Inside parent process, going to wait!\n");
    wait(NULL);
  }
  return 0;
}