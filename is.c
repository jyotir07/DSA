#include <stdio.h>
#include <time.h>

void insertionSort(int arr[], int n)
{
  int i, key, j;
  for (i = 1; i < n; i++)
  {
    key = arr[i];
    j = i - 1;

    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

double cpu_time_used(clock_t start, clock_t end)
{
  return ((double)(end - start)) / CLOCKS_PER_SEC;
}

// function to perform binary search
int binarySearch(int arr[], int size, int target)
{
  int left = 0;
  int right = size - 1;

  while (left <= right)
  {
    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
    {
      return mid; // Element found at index 'mid'
    }
    else if (arr[mid] < target)
    {
      left = mid + 1; // Search in the right half
    }
    else
    {
      right = mid - 1; // Search in the left half
    }
  }

  return -1; // Element not found
}

int linearSearch(int arr[], int n, int target)
{
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == target)
    {
      return i; // Return the index where the target is found
    }
  }
  return -1; // Return -1 if target is not found in the array
}

int main()
{
  int n;
  int target;
  printf("Enter the number of elements: ");
  scanf("%d", &n);

  int arr[n];
  int size = sizeof(arr) / sizeof(arr[0]);

  printf("Enter the elements:\n");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  printf("unsorted array: ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }

  insertionSort(arr, n);
  printf("\n");

  printf("Sorted array: ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");

  clock_t start = clock();
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }

  // int result = linearSearch(arr, n, target);

  // if (result != -1) {
  //     printf("Element %d found at index %d\n", target, result);
  // } else {
  //     printf("Element %d not found in the array\n", target);
  // }

  printf("\nEnter target element from the above array: ");
  scanf("%d ", &target);
  binarySearch(arr, size, target);

  if (n != -1)
  {
    printf("Element %d found at index %d.\n", target, n);
  }
  else
  {
    printf("Element %d not found in the array.\n", target);
  }

  clock_t end = clock();
  double cpuTime = cpu_time_used(start, end);
  printf("CPU time used: %.10f seconds", cpuTime);
  return 0;
}
