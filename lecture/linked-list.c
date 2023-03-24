#include <stdio.h>
#include <stdlib.h>

struct Node__ {
    int value;
    struct Node__* next;            /* link to next node */  
};

typedef struct Node__ Node;
typedef Node* NodePtr;

void printList(NodePtr start) {
    NodePtr current = start;
    while (current != NULL) {
      printf("%d -> ", current -> value);
      current = current -> next;
    }
    printf("\n");
}

// add values in front
// no need for loop, add infront then move NULL to the last node
void addFirst(NodePtr* startPtr, int value) {
    NodePtr temp = (NodePtr)malloc(sizeof(Node));
    temp->value = value;
    if (*startPtr == NULL) {
      temp->next = NULL;          /* temp is the last Node */
      *startPtr = temp;
    } else {
      temp->next = *startPtr;
      *startPtr = temp;
    }
}

// add values in the back
// loop to find the last value first, then add new value onto list
void addLast(NodePtr* startPtr, int value) {
    NodePtr temp = (NodePtr)malloc(sizeof(Node));
    temp->value = value;
    temp->next = NULL;
    if (*startPtr == NULL) {
      *startPtr = temp;
    } else {
        NodePtr current = *startPtr;
        while (current->next != NULL) {
          current = current->next;
        }
        current->next = temp;
    }
}

void delete(NodePtr* startPtr, int value) {
    if (startPtr != NULL) {
        NodePtr current = *startPtr;
        NodePtr previous = NULL;
        while (current->next != NULL && current->value != value) {                 /* loop to find the last value */
          previous = current;
          current = current->next;
        }

        if (current->value == value) {
            printf("Found: %d\n", current->value);
            if (previous == NULL) {
              *startPtr = current->next;
              free(current);
            } else {
              previous->next = current->next;
              free(current);
            }
        }
    }
}

int main() {
    NodePtr startPtr;               /* points to the start of a linked list (ALWAYS) */
    startPtr = NULL;                /* initialize linked list with a default value */

    // printf("by adding first: \n");
    // addFirst(&startPtr, 50);
    // addFirst(&startPtr, 20);
    // addFirst(&startPtr, 30);
    // addFirst(&startPtr, 10);
    // addFirst(&startPtr, 60);
    // printf("\n");

    printf("by adding last: \n");
    addLast(&startPtr, 0);
    addLast(&startPtr, 50);
    addLast(&startPtr, 20);
    addLast(&startPtr, 30);
    addLast(&startPtr, 10);
    addLast(&startPtr, 50);
    addLast(&startPtr, 60);
    printf("\n");

    printf("before deletion: \n");
    printList(startPtr);
    printf("\nafter deletion: \n");
    delete(&startPtr, 20);
    delete(&startPtr, 50);
    printList(startPtr);

}