/*
Q1. Write a C/C++ program to implement below mentioned Searching
and Sorting Techniques.
(a) Merge Sort
(b) Quick Sort
(c) Heap Sort
*/
#include <stdio.h>
#include <stdlib.h>

void mergeSort(int arr[], int size, int low, int up);
void quickSort(int arr[], int low, int up);
void heapSort(int arr[], int size);

#define PARENT(i) (i / 2)
#define LEFT(i) (2 * i)
#define RIGHT(i) (2 * i + 1)

int main()
{
    int n, choice;
    printf("Enter the Size of Array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the Element for Array:- \n");
    for (int i = 1; i <= n; i++)
    {
        printf("For Index [%d]: ", i);
        scanf("%d", &arr[i]);
    }

    while (1)
    {
        printf("\n*************************\n");
        printf(" 1. Merge Sort\n 2. Quick Sort\n 3. Heap Sort\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            mergeSort(arr, n, 0, n);
            printf("SORTED: \n");
            for (int i = 1; i <= n; i++)
            {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;
        case 2:
            quickSort(arr, 0, n);
            printf("SORTED: \n");
            for (int i = 1; i <= n; i++)
            {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;
        case 3:
            heapSort(arr, n);
            printf("SORTED: \n");
            for (int i = 1; i <= n; i++)
            {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;
        case 4:
            exit(1);
        default:
            printf("Invalid Choice\n");
        }
    }
}

void mergeSort(int arr[], int size, int low, int up)
{
    if (low < up)
    {
        int mid = (low + up) / 2;          // Mid
        mergeSort(arr, size, low, mid);    // Call recursion for first half of array
        mergeSort(arr, size, mid + 1, up); // Call recursion for second half of array

        int temp[size];
        int i = low, j = mid + 1, k = low;

        while (i <= mid && j <= up) // i pointer from low to mid and j pointer from mid + 1 to up
        {
            if (arr[i] <= arr[j]) // check if i is greater or smaller than j
            {
                temp[k++] = arr[i++]; // add i to temporary array in k-th address
            }
            else
            {
                temp[k++] = arr[j++]; // add j to temporary array in k-th address
            }
        }

        while (i <= mid) // add remaining array of first half if remaining
        {
            temp[k++] = arr[i++];
        }
        while (j <= up) // add remaining array of second half if remaining
        {
            temp[k++] = arr[j++];
        }

        for (int i = low; i <= up; i++) // move all value from temporary arrary to main array
        {
            arr[i] = temp[i];
        }
    }
}

void quickSort(int arr[], int low, int up)
{
    if (low < up)
    {
        int pivot = arr[low], i = low + 1, j = up, temp; // create a pivot at starting index of array

        while (i <= j)
        {
            while (i <= up && arr[i] < pivot)
                i++; // check which value of i-th is less than pivot
            while (j > low && arr[j] >= pivot)
                j--; // check which value of j-th is more than pivot

            if (i < j) // swaping location
            {
                temp = arr[i];
                arr[i++] = arr[j];
                arr[j--] = temp;
            }
        }

        arr[low] = arr[j]; // set lower bound of array to j-th value
        arr[j] = pivot;    // set pivot location to j-th place

        quickSort(arr, low, j - 1); // recursive call from low till pivot
        quickSort(arr, j + 1, up);  // recusive call from pivot + 1 till up
    }
}

void heapSort(int arr[], int size)
{
    // Build the heap
    for (int i = size / 2; i >= 1; i--) // travesal from last node to root node
    {
        for (int j = i; LEFT(j) <= size;)
        {
            int largest = j;
            if (LEFT(j) <= size && arr[LEFT(j)] > arr[largest])
            {
                largest = LEFT(j);
            }
            if (RIGHT(j) <= size && arr[RIGHT(j)] > arr[largest])
            {
                largest = RIGHT(j);
            }
            if (largest == j)
            {
                break;
            }

            // Swap
            int temp = arr[j];
            arr[j] = arr[largest];
            arr[largest] = temp;
            j = largest; // Move down the tree
        }
    }

    // Sort the array
    for (int i = size; i > 1; i--)
    {
        // Swap the root with the last element
        int max = arr[1];
        arr[1] = arr[i];
        arr[i] = max;
        // Restore the heap property
        for (int j = 1; LEFT(j) <= i - 1;)
        {
            int largest = j;
            if (LEFT(j) <= i - 1 && arr[LEFT(j)] > arr[largest])
            {
                largest = LEFT(j);
            }
            if (RIGHT(j) <= i - 1 && arr[RIGHT(j)] > arr[largest])
            {
                largest = RIGHT(j);
            }
            if (largest == j)
            {
                break;
            }

            // Swap
            int temp = arr[j];
            arr[j] = arr[largest];
            arr[largest] = temp;
            j = largest; // Move down the tree
        }
    }
}
