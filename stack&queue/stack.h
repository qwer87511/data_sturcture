#include <stdbool.h>

typedef struct _node {
  char data;
  struct _node* next;
} Node;

void push(Node** top, int item);

int pop(Node** top);

int top(Node* top);

bool isEmpty(Node* top);
