#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    const unsigned int sizeOfArray = 100;
    int *data = (int *)malloc(sizeOfArray * sizeof(int));
    free(data);

    printf("El: %d\n", data[1]);
    return 0;
}