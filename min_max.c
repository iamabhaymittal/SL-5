#include <stdio.h>
#include <stdlib.h>

int arr[]= {10, 1000, -2, 25, 44, 33, 22,999,44};

struct min_max
{
    int min;
    int max;
};

void printArray(int left, int right)
{
    int i;
    printf("\n");
    for (i = left; i < right; i++)
    {
        printf("%d ", arr[i]);
    }
}

struct min_max maxMin(int i, int j)
{
    printArray(i, j);
    int mid;
    struct min_max current;
    struct min_max left;
    struct min_max right;

    if (i == j)
    {
        current.max = arr[i];
        current.min = arr[i];
        return current;
    }
    else if (i == j + 1)
    {
        if (arr[i] > arr[j])
        {
            current.max = arr[i];
            current.min = arr[j];
        }
        else
        {
            current.max = arr[j];
            current.min = arr[i];
        }
        return current;
    }
    else
    {

        mid = (i + j) / 2;
        printf("\nLeft half:");
        printArray(i, mid);
        left = maxMin(i, mid);
        printf("\nRight half:");
        printArray(mid + 1, j);
        right = maxMin(mid + 1, j);
        if (left.min < right.min)
        {
            current.min = left.min;
        }
        else
        {
            current.min = right.min;
        }
        if (left.max > right.max)
        {
            current.max = left.max;
        }
        else
        {
            current.max = right.max;
        }
        return current;
    }
}

void main()
{
    int i, j, k;

    //printf("Enter array size:");
    //scanf("%d", &size);
    /*for (i = 0; i < size; i++)
    {
        printf("Arr[%d]:", i);
        scanf("%d", &arr[i]);
    }*/
    //arr = {10, 1000, -2, 25, 44, 33, 22};
    struct min_max result = maxMin(0, size - 1);
    printf("%d %d", result.max, result.min);
}




