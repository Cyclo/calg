#include <stdio.h>

// A queue implementation from Introduction to algorithms on page 234
// Each operation takes O(1) time
//
// This method implements a queue of at most (n-1) elements using an array
// Q[0..n] Q.head, Q.head+1, Q.head+2 ... Q.tail-1
// 


#define QUEUE_SIZE 12

struct queue{
  unsigned int head;
  unsigned int tail;

  int queue[QUEUE_SIZE];
};

typedef struct queue queue;

void 
enqueue(queue *q, int x)
{
  if(q->head == (q->tail+1)){
    fprintf(stderr,"Queue Overflow!\n");
    return;
  }

  q->queue[q->tail] = x;
 
  // End of queue? Go to start 
  if(q->tail == QUEUE_SIZE-1){
    q->tail = 0;
  }else{
    q->tail++;
  }
}

int 
dequeue(queue *q)
{
  if(q->head == q->tail){
    fprintf(stderr,"Queue Underflow!\n");
    return -1;
  }

  int x;
  x = q->queue[q->head];
  
  if(q->head == QUEUE_SIZE-1){
    q->head = 0;
  }else{
    q->head++;
  }

  return x;
}


int
main()
{
  // Must initiali
  queue qt = {0};
  queue *q = &qt;

  enqueue(q,10);
  
  printf("%d\n",dequeue(q));

  dequeue(q);

  int i = 0;

  for(i = 0; i < 11; i++){
    enqueue(q,i);
  }
  for(i = 0; i < 11; i++){
    printf("%d\n",dequeue(q));
  }


  return 0;
}
