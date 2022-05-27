#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    const unsigned int sizeOfArray = 100;
    int *data = (int *)malloc(sizeOfArray * sizeof(int));

    data[sizeOfArray] = 0;
    free(data);
    return 0;
}