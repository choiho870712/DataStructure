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

template <typename T>
void swap(T &value1, T &value2)
{
    T temp = value1;
    value1 = value2;
    value2 = temp;
} // swap()

int main()
{
    float *floatPointer = NULL;
    float *floatPointer2 = NULL;

    memoryAllocation(floatPointer);
    memoryAllocation(floatPointer2);

    *floatPointer = 3.14;
    *floatPointer2 = 3.1415926;

    swap(*floatPointer, *floatPointer2);

    printf("float = %f, float2 = %f\n", *floatPointer, *floatPointer2);

    free(floatPointer);
    free(floatPointer2);
} // main()
