#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *data = (int *) malloc(sizeof(int));
    *data = 5;
    printf("Data is: %d\n", *data);
    return 0;
}