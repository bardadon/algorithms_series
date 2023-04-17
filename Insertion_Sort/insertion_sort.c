#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5 /*Array length*/

void insertion_sort(int arr[]);

int main(void)
{
    /*Initialize variables*/
    int i;
    int arr[MAXSIZE] = {5, 2, 4, 6, 1};

    /*Apply insertion sort*/
    insertion_sort(arr);

    /*Print results*/
    for (i = 0; i < MAXSIZE; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    /*return stats*/
    return 0;
}

void insertion_sort(int arr[])
{
    int i, j, key;
    key = 0;

    for (j = 1; j < MAXSIZE; j++)
    {
        key = arr[j]; /*Set current index*/
        i = j - 1; /*Set previous index*/

        /*Found unsorted values*/
        while(arr[i] > key && i >= 0)
        {
            arr[i+1] = arr[i]; /*Swapping them*/
            i = i - 1; /*Comparing the previous pair*/
        }
        arr[i+1] = key; /*Inserting the key in the correct position*/
    }
}

