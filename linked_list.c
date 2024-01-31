#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Define the structure of a linked list node
struct Node {
  int data;
  struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  if (newNode == NULL) {
    printf("Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Function to delete a node from the middle of the linked list
void deleteFromMiddle(struct Node **head, int size) {
  if (*head == NULL || size <= 0) {
    printf("Invalid linked list or size\n");
    return;
  }

  // Find the middle position
  int middle = size / 2;
  if (size % 2 == 0) {
    // If the size is even, move to the previous node
    middle--;
  }

  // Traverse to the middle node
  struct Node *current = *head;
  struct Node *prev = NULL;
  for (int i = 0; i < middle && current != NULL; i++) {
    prev = current;
    current = current->next;
  }

  if (current == NULL) {
    printf("Invalid middle position\n");
    return;
  }

  // Adjust pointers to bypass the middle node
  if (prev != NULL) {
    prev->next = current->next;
  } else {
    // If the middle node is the first node
    *head = current->next;
  }

  // Free the memory occupied by the middle node
  free(current);
}

// Function to print the linked list
void printList(struct Node *head) {
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

int main() {
  int len_arr[] = {10,      100,      1000,      10000,     100000,
                   1000000, 10000000, 100000000, 1000000000};
  for (int i = 0; i < 9; i++) {
    int len = len_arr[i];
    struct Node *head = NULL;
    struct Node *current;
    // Create a linked list with values from 1 to len
    for (int i = 1; i <= len; i++) {
      struct Node *newNode = createNode(i);
      if (head == NULL) {
        head = newNode;
        current = head;
      } else {
        current->next = newNode;
        current = newNode;
      }
    }
    clock_t start = clock(); // printList(head);
    deleteFromMiddle(&head, len);
    clock_t end = clock();
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Size of List: %d \n", len);
    printf("Execution time: %f seconds\n\n", cpu_time_used);
    sleep(2);
  }
  return 0;
}
