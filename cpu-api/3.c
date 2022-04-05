#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  int rc = fork();

  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    printf("Hello!\n");
  } else {
    // Perform dummy IO to make sure the process is preempted to the child.
    const int numberOfIORequests = 5;
    for (int i = 0; i < numberOfIORequests; ++i)
    {
      FILE *file = fopen("../dummy.txt", "w+");
      fclose (file);
    }

    printf("Goodbye!\n");
  }

  return 0;
}