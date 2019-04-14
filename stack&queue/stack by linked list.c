#include<stdio.h> // standard input output
#include<stdlib.h> // standard library
#include<string.h>

typedef struct _node {
  int data;
  struct _node* next;
} Node;

Node* top = NULL;

int push(int item) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = item;
  newNode->next = top;
  top = newNode;
  if(top == NULL) printf("qwer\n");
}

int pop() {
  if(top == NULL) return -1;

  Node* oldNode = top;
  top = top->next;
  int item = oldNode->data;
  free(oldNode);
  return item;
}

int main() {
  while(1) {
    char ins[30];
    scanf("%s", ins);
    if(!strncmp(ins, "push", 4))
    {
      scanf("%s", ins);
      push(atoi(ins));
    }
    else if(!strncmp(ins, "pop", 3)) {
      printf("%d\n", pop());
    }
  }
}
