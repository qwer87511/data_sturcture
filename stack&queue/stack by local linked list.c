#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct _node {
  int data;
  struct _node* next;
} Node;

int push(Node** top, int item) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = item;
  newNode->next = *top;
  *top = newNode;
}

int pop(Node** top) {
  if(*top == NULL) return -1;
  Node* oldNode = *top;
  *top = (*top)->next;
  int item = oldNode->data;
  free(oldNode);
  return item;
}

int main() {
  Node* top = NULL;

  while(1) {
    char ins[30];
    scanf("%s", ins);
    if(!strncmp(ins, "push", 4))
    {
      scanf("%s", ins);
      push(&top, atoi(ins));
    }
    else if(!strncmp(ins, "pop", 3)) {
      printf("%d\n", pop(&top));
    }
  }
}
