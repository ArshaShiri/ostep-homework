#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  FILE *file = fopen("../p2.txt", "w+");

  char line1[] = "Before forking\n";
  fputs(line1, file);

  // Force flushing the buffer before forking!
  fflush(file);

  int rc = fork();
  char line2[] = "After forking\n";
  fputs(line2, file);

  if (rc < 0 || file < 0) {
    fprintf(stderr, "Fork failed\n");
    exit(1);
  } else if (rc == 0) {
    char line3[] = "I am the child process!\n";
    fputs(line3, file);
  } else {
    char line4[] = "I am the parent process!\n";
    fputs(line4, file);
  }

  fclose (file);
  return 0;
}