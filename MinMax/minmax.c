#include <stdio.h>
#include <stdlib.h>

int max, min;
int arr[20];

void minmax(int i, int j)
{

    int max1, min1;

    if (i == j)
    {
        min = max = arr[i];
    }
    else if (i == j - 1)
    {

        if (arr[i] > arr[j])
        {
            max = arr[i];
            min = arr[j];
        }
        else
        {
            max = arr[j];
            min = arr[i];
        }
    }
    else
    {

        int mid = (i + j) / 2;

        minmax(i, mid);
        printf("\n===================================================\n");
        printf("\n{\t");
        for (int k = i; k <= mid; k++)
            printf("%d\t", arr[k]);
        printf("}");

        printf("\n\t\tStart :: %d", i);
        printf("\n\t\tEnd :: %d", mid);
        printf("\nMax :: %d", max);
        printf("\nMin :: %d", min);

        max1 = max;
        min1 = min;

        minmax(mid + 1, j);
        printf("\n===================================================\n");
        printf("\n{\t");
        for (int k = mid + 1; k <= j; k++)
            printf("%d\t", arr[k]);
        printf("}");

        printf("\n\t\tStart :: %d", mid + 1);
        printf("\n\t\tEnd :: %d", j);
        printf("\nMax :: %d", max);
        printf("\nMin :: %d", min);

        if (max1 > max)
            max = max1;
        if (min1 < min)
            min = min1;
    }
}

int main()
{
    int i, size;
    printf("Enter the size of array :: ");
    scanf("%d", &size);

    printf("Enter the elements of array :: \n");
    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    min = max = arr[0];
    printf("Array elements are :: {\t");
    for (i = 0; i < size; i++)
        printf("%d\t", arr[i]);
    printf("\t}");

    minmax(0, size - 1);

    printf("\n\n================Min and Max===============\n");
    printf("\n Final Max :: %d", max);
    printf("\n Final Min :: %d\n", min);
    return 0;
}
