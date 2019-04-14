#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NUM 50

int stack[NUM];
int top = -1;

int push(int stack[], int item) {
  if (top == NUM - 1) return -1; // stack overflow
  top++;
  stack[top] = item;
}

int pop(int stack[]) {
  if (top == -1) return -1; // stack empty
  int item = stack[top];
  top--;
  return item;
}

int main() {
  while(1) {
    char ins[30];
    scanf("%s", ins);
    if(!strncmp(ins, "push", 4))
    {
      scanf("%s", ins);
      push(stack, atoi(ins));
    }
    else if(!strncmp(ins, "pop", 3)) {
      printf("%d\n", pop(stack));
    }
  }
}
