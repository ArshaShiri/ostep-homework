#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    printf("pid: %d\n", getpid());

    long long memoryMegabytes;
    printf("Enter the amount of memory used by this program in megabytes. \n");
    scanf("%lld", &memoryMegabytes);

    const long long memoryByte = memoryMegabytes * (long long)1024 * 1024;
    printf("memoryByte is %lld \n", memoryByte);
    int *arr = malloc(memoryByte);

    const long long length = (long long)(memoryByte / sizeof(int));
    printf("Size of array is %lld \n", length);

    while (1)
    {
        for (long long i = 0; i < length; i++)
            arr[i] += 1;

        for (int i = 0; i < length; i++)
            arr[i] -= 1;
    }

    free(arr);
    return 0;
}