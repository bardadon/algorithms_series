#include <stdio.h>
#include <math.h>
#include "data.h"

/*
Function: parent

Input: 
    i - the index of the child
Output: 
    the index of the parent
Description: 
    This function returns the index of the parent of the child
Algorithm: 
    The index of the parent is floor(i/2)
*/
int parent(int i)
{
    return floor(i/2);
}

int left(int i)
{
    return 2*i + 1;
}

int right(int i)
{
    return 2*i + 2;
}


/*
Function: exchange

Input: 
    A - the array
    parent - the index of the parent
    child - the index of the child
Output:
    None
Description:
    This function exchanges the parent and the child
Algorithm:
    temp = A[parent]
    A[parent] = A[child]
    A[child] = temp
*/
void exchange(int A[], int parent, int child)
{
    int temp;
    temp = 0;

    temp = A[parent];
    A[parent] = A[child];
    A[child] = temp;
}


/*
Function: max_heapify

Input: 
    A - the array
    i - the index of the parent
    heap_size - the size of the heap
Output:
    None
Description:
    This function makes sure that the parent is bigger than the children
Algorithm in simple words:
    1. Check if the parent is bigger than the children
    2. If not, exchange the parent with the biggest child
    3. Call heapify again on the child that has now lowered down in the tree
*/
void max_heapify(int A[], int i, int heap_size)
{
    int l, r, largest;

    l = 0;
    r = 0;
    largest = 0;

    /*Set l and r to be the left and right sons*/
    l = left(i);
    r = right(i);

    /*Check who is larger out of A[i], left child, right child*/
    if (l < heap_size && A[l] > A[i])
    {
        largest = l;
    }
    else
    {
        largest = i;
    }

    if (r < heap_size && A[r] > A[largest])
    {
        largest = r;
    }

    /*Current, largest is the biggest among A[i], left child, right child*/
    /*Now we want to switch between the A[i] and A[largest]*/

    /*If one of the childern is bigger*/
    if (largest != i)
    {
        /*exchange parent and child*/
        printf("Exchanging %d and %d, i = %d, largest = %d \n", A[i], A[largest], i, largest);
        exchange(A, i, largest);

        /*And call heapify again on the parent that has now lowered down in the tree*/
        printf("Calling heapify again on %d, largest = %d \n", A[i], largest);
        max_heapify(A, largest, heap_size);
    }


}

/*
Function: min_heapify

Input: 
    A - the array
    i - the index of the parent
    heap_size - the size of the heap
Output:
    None
Description:
    This function makes sure that the parent is smaller than the children
Algorithm in simple words:
    1. Check if the parent is smaller than the children
    2. If not, exchange the parent with the smallest child
    3. Call heapify again on the child that has now lowered down in the tree
*/
void min_heapify(int A[], int i, int heap_size)
{
    int l, r, smallest;

    /*Set l and r to be the left and right sons*/
    l = left(i);
    r = right(i);

    /*Check who is larger out of A[i], left child, right child*/
    if (l < heap_size && A[l] < A[i])
    {
        smallest = l;
    }
    else
    {
        smallest = i;
    }

    if (r < heap_size && A[r] < A[smallest])
    {
        smallest = r;
    }

    /*Current, smallest is the lowest among A[i], left child, right child*/
    /*Now we want to switch between the A[i] and A[smallest]*/

    /*If one of the childern is smaller*/
    if (smallest != i)
    {
        /*exchange parent and child*/
        printf("Exchanging %d and %d, i = %d, smallest = %d \n", A[i], A[smallest], i, smallest);
        exchange(A, i, smallest);

        /*And call heapify again on the parent that has now lowered down in the tree*/
        printf("Calling heapify again on %d, smallest = %d \n", A[i], smallest);
        min_heapify(A, smallest, heap_size);
    }


}

/*
Function: build_max_heap

Input: 
    A - the array
Output:
    None
Description:
    This function builds a max heap
Algorithm in simple words:
    1. Start from the middle of the array
    2. Call heapify on the parent
    3. Go to the next parent and call heapify on it
    4. Repeat until you reach the first parent
*/
void build_max_heap(int A[], int heap_size)
{
    int i;
    /*Build max heap*/
    for (i = heap_size/2 - 1; i>=0 ; i--)
    {
        max_heapify(A, i, heap_size);
    }  

    /*Print the heap*/
    printf("Finished Building the heap. The heap is: ");
    for (i = 0; i < heap_size; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}



void heap_sort(int A[], int array_size, int heap_size)
{
    int i;

    /*Create a max heap out of the array*/
    printf("Building the heap\n");
    build_max_heap(A, heap_size);

    printf("\nSorting the heap\n");
    for (i = array_size-1; i >= 1; i--)
    {
        exchange(A, i, 0);
        heap_size = heap_size - 1;
        max_heapify(A, 0, heap_size);
    }
}
