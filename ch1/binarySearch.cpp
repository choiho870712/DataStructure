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


template <typename T>
int compare(T value1, T value2)
{
    if (value1 > value2) return 1;
    if (value1 < value2) return -1;
    return 0;
} // compare()


template <typename T>
int binarySearch(T* list, int size, T searchNumber)
{
    int left = 0;
    int right = size;
    while (left <= right) {
        int middle = (left + right)/2;
        switch (compare(list[middle], searchNumber)) {
            case -1: left = middle + 1; break;
            case 1: right = middle - 1; break;
            case 0: return middle;
        } // switch
    } // while

    return -1;
} // binarySearch()



int main(void)
{
    int size = 0;
    int *list = NULL;

    printf("Enter the number of numbers to generate: \n");
    scanf("%d", &size);

    if (size < 1)
        reportErrorAndExitProgram("Improper value of size");

    memoryAllocationArray(list, size);
    randomArray(list, size);
    printIntegerArray(list, size);
    selectionSort(list, size);
    printIntegerArray(list, size);


    int searchNumber = 0;

    printf("Enter the search number to generate: \n");
    scanf("%d", &searchNumber);

    if (searchNumber < 0 || searchNumber > 1000)
        reportErrorAndExitProgram("Improper value of searchNumber");


    int position = binarySearch(list, size, searchNumber);
    printf("The position of %d is at %d\n", searchNumber, position);

    free(list);

} // main()
