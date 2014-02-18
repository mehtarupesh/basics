// quickSort.c
#include <stdio.h>

void quickSort( int[], int, int);
int partition( int[], int, int);
void print_array(int[],int);

void main() 
{
    int a[] = {9,8,7,6,5,4,3,2,1};

    int i;
    printf("Unsorted array is: \n ");
    print_array(a,9);

    quickSort( a, 0, 8);

    printf("Sorted array is: \n ");
    print_array(a,9);

}



void quickSort( int a[], int l, int r)
{
   int j;

   if( l < r ) 
   {
    // divide and conquer
        j = partition( a, l, r);
       quickSort( a, l, j-1);
       quickSort( a, j+1, r);
   }
    
}



int partition( int a[], int l, int r) {
   int pivot, i, j, t;
   pivot = a[l];
   i = l; j = r+1;
        
   while( 1)
   {
    do ++i; while( a[i] <= pivot && i <= r );
    do --j; while( a[j] > pivot );
    if( i >= j ) break;
    t = a[i]; a[i] = a[j]; a[j] = t;
    print_array(a,9);
   }
   t = a[l]; a[l] = a[j]; a[j] = t;
   return j;
}


void print_array(int a[],int n)
{
    int i;
    for(i = 0; i < n; ++i)
        printf(" %d ", a[i]);
    printf("\n");
}




