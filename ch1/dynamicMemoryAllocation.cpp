# include <stdio.h>
# include <stdlib.h>

template <typename T>
void memoryAllocation(T* &pointer)
{
    if (!(pointer = (T*)malloc(sizeof(T)))) {
        fprintf(stderr, "Insufficient memory");
        exit(EXIT_FAILURE);
    }
} // memoryAllocation()

int main()
{
    int *intPointer = NULL;
    float *floatPointer = NULL;

    memoryAllocation(intPointer);
    memoryAllocation(floatPointer);

    *intPointer = 1024;
    *floatPointer = 3.14;

    printf("int = %d, float = %f    \n", *intPointer, *floatPointer);

    free(intPointer);
    free(floatPointer);
} // main()
