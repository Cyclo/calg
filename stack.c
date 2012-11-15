#include <stdio.h>

// Simple stack implementation based of the pseudo code in Introduction
// to algorithms on page 232. All operations should be O(1) time

// Stacks are LIFO, last-in-first-out, queues are FIFO

#define MAX_STACK 255

struct stack{
  
  unsigned int top;
  int stack[MAX_STACK];

};

typedef struct stack stack;

int 
stack_empty(stack *s)
{
  if(s->top == 0){
    return 1;
  }

  return 0;
}

int
stack_push(stack *s, int x)
{
  
  if((s->top + 1) >= MAX_STACK){
    fprintf(stderr,"Stack Overflow!\n");
    return -1;
  }
  
  s->stack[++(s->top)] = x;
  return 1;
}

int 
stack_pop(stack *s)
{

  if(stack_empty(s)){
    fprintf(stderr,"Stack Underflow!\n");
    return -1;
  }

  return s->stack[s->top--];
}


int
main()
{

  stack ls = {0};
  stack *s = &ls;

  if(stack_empty(s)){
    printf("Stack Empty\n");
  }

  stack_push(s,10);
  stack_push(s,30);
  stack_push(s,25);

  printf("%d\n",stack_pop(s));

  stack_pop(s);
  stack_pop(s);

  int i;
  for(i=0;i < 1000000; i++){
    stack_push(s,i);
    stack_pop(s);
  }

}

