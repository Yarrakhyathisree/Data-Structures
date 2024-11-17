#include <stdio.h>
//quick sort
// Function to swap two elements
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(int arr[], int low, int high)
 {
    int pivot = arr[high]; // Selecting pivot as the last element
    int left = low;
    int right = high;

    while (left < right)
	{
        // Move left index to the right
        while (arr[left] < pivot) 
		{
            left++;
        }

        // Move right index to the left
        while (arr[right] > pivot) 
		{
            right--;
        }

        // Swap arr[left] and arr[right] if left < right
        if (left < right) 
		{
            swap(&arr[left], &arr[right]);
            left++;
            right--;
        }
    }

    // Swap arr[left] and arr[high]
    swap(&arr[left], &arr[high]);

    return left;
}

// QuickSort function
void quickSort(int arr[], int low, int high) 
{
    if (low < high) 
	{
        // call Partition function to find Partition Index
        int partitionIndex = partition(arr, low, high);

        // Recursively call quickSort() for left and right
        // half based on partition Index
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

// driver code
int main() 
{
	int i;
    int arr[] = { 19, 17, 15, 12, 16, 18, 4, 11, 13 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // printing the original array
    printf("Original array: ");
    for (i = 0; i < n; i++) 
	{
        printf("%d ", arr[i]);
    }

    // calling quickSort() to sort the given array
    quickSort(arr, 0, n - 1);

    // printing the sorted array
    printf("\nSorted array: ");
    for (i = 0; i < n; i++) 
	{
        printf("%d ", arr[i]);
    }

    return 0;
}
