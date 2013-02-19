#include <stdio.h>

// The quick sort algorithm is commonly used because of it's good average runtime
// of O(n lg n) and worst case runtime of O(n^2)

// The quick sort algorithm uses the divide and conquer paradigm.


void
swap(int *a, int *b) 
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int 
partition(int a[], int p, int r) 
{
  int x,i,j;
  x = a[r];
  i = p - 1;

  for( j = p; j <= r-1; j++) {

    // If our current element is <= to the pivot
    // swap it with an item that's >= to the pivot
    if(a[j] <= x) {
      i++;
      swap(&a[i],&a[j]);
    }
  }

  // Put pivot in correct place
  swap(&a[i+1], &a[r]);

  // Return pivot location
  return i+1;
}

void 
quicksort(int a[], int p, int r)
{
  if(p >= r) return;

  int q;
  q = partition(a, p, r);

  quicksort(a, p, q-1);
  quicksort(a, q + 1, r);
}


int
main()
{

  int arr[10] = { 9, 4, 1, 7, 9, 6, 3, 9, 8, 5 };

  quicksort(arr, 0, 9);

  int i;
  for(i = 0; i < 10; i++) {
    printf("%d", arr[i]);
  }

  putchar('\n');

  return 0;
}