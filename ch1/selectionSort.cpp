# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

void reportErrorAndExitProgram(const char *message);
template <typename T> void memoryAllocation(T* &pointer);
template <typename T> void swap(T &value1, T &value2);
template <typename T> void memoryAllocationArray(T* &array, int size);
template <typename T> void randomArray(T* array, int size);
void printIntegerArray(const int* array, int size);
template <typename T> void selectionSort(T* list, int size);


void reportErrorAndExitProgram(const char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(EXIT_FAILURE);
} // reportErrorAndExitProgram()


template <typename T>
void memoryAllocation(T* &pointer)
{
    if (!(pointer = (T*)malloc(sizeof(T))))
        reportErrorAndExitProgram("Insufficient memory");
} // memoryAllocation()


template <typename T>
void swap(T &value1, T &value2)
{
    T temp;
    SWAP(value1, value2, temp);
} // swap()


template <typename T>
void memoryAllocationArray(T* &array, int size)
{
    if (!(array = (T*)malloc(sizeof(T)*size)))
        reportErrorAndExitProgram("Insufficient memory");
} // memoryAllocationArray()


template <typename T>
void randomArray(T* array, int size)
{
    for (int i = 0; i < size; i++)
        array[i] = rand() % 1000;
} // memoryAllocationArray()


void printIntegerArray(const int* array, int size)
{
    for (int i = 0; i < size; i++)
        printf("%3d ", array[i]);
    printf("\n");
} // printIntegerArray()


template <typename T>
void selectionSort(T* list, int size)
{
    for (int i = 0; i < size-1; i++) {
        int minValuePosition = i;
        for (int j = i+1; j < size; j++)
            if (list[j] < list[minValuePosition])
                minValuePosition = j;
        swap(list[i], list[minValuePosition]);
    } // for
} // selectionSort()


int main(void)
{
    int number = 0;
    int *list = NULL;

    printf("Enter the number of numbers to generate: \n");
    scanf("%d", &number);

    if (number < 1)
        reportErrorAndExitProgram("Improper value of number");

    memoryAllocationArray(list, number);
    randomArray(list, number);
    printIntegerArray(list, number);
    selectionSort(list, number);
    printIntegerArray(list, number);

    free(list);

} // main()
