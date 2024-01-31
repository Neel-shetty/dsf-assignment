#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Function to delete an element from the middle of an array
void deleteFromMiddle(int *arr, int *size, int indexToDelete) {
  if (indexToDelete < 0 || indexToDelete >= *size) {
    printf("Invalid index to delete\n");
    return;
  }

  // Shift elements after the deletion point
  for (int i = indexToDelete; i < *size - 1; i++) {
    arr[i] = arr[i + 1];
  }

  // Decrease the size of the array
  (*size)--;
}

int main() {
  int len_arr[] = {10,      100,      1000,      10000,     100000,
                   1000000, 10000000, 100000000, 1000000000};
  for (int i = 0; i < 9; i++) {
    int len = len_arr[i];
    int *arr = malloc(len * sizeof(int));
    if (arr == NULL) {
      printf("Memory allocation failed\n");
      return 1;
    }
    int size = len;
    for (int i = 0; i < size; i++) {
      arr[i] = i + 1;
    }
    int indexToDelete = size / 2;
    clock_t start = clock();
    deleteFromMiddle(arr, &size, indexToDelete);
    clock_t end = clock();
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Size of List: %d \n", len);
    printf("Execution time: %f seconds\n\n", cpu_time_used);
    free(arr); // Don't forget to free the allocated memory
    sleep(2);
  }
  return 0;
}
