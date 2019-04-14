#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NUM 10

int push(int stack[], int* top, int item) {
  if(*top == NUM - 1) return -1;
  stack[++(*top)] = item;
}

int pop(int stack[], int* top) {
  if (*top == -1) return -1;
  return stack[(*top)--];
}

int main(int argc, char** argv) {
  int top = -1;
  int stack[NUM];
  while(1) {
    char ins[30];
    scanf("%s", ins);
    if(!strncmp(ins, "push", 4))
    {
      scanf("%s", ins);
      push(stack, &top, atoi(ins + 4));
    }
    else if(!strncmp(ins, "pop", 3)) {
      printf("%d\n", pop(stack, &top));
    }
  }
}
