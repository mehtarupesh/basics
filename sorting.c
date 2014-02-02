/* Sorting algorithms */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


#define PARENT(i)   ((i - 1)/2)
#define LEFT_CHILD(i)   (2*i + 1)
#define RIGHT_CHILD(i)   (2*i + 2)


void bubbleSort(int *a,int num);
void insertionSort(int *a,int num); 
void mergeSort(int *a,int start,int end);

void swap(int *a,int *b);
void buildHeap(int *a,int num);
void removeRoot(int *a,int num);
void heapSort(int *a,int num);
void printArray(int *a, int num);



void main()
{
    srand(time(NULL));

    int a[20],b[10];
    int i;

    for(i=0;i < 20;i++){
        a[i] = rand() % 50;

        if(i < 10)b[i] = rand() % 50;
    }

    printf("Before\n");
    printArray(b,10);   

    buildHeap(b,10);

    printf("After\n");
    printArray(b,10);    

    printf("Heaping...\n");
    heapSort(b,10);
    
    printf("After Heap Sort\n");
    printArray(b,10);    

    return;
    printf("Before\n");
    printArray(a,20);   

    mergeSort(a,0,19);

    printf("After\n");
    printArray(a,20);    
}  

void heapSort(int *a,int num)
{
    int i;
    for(i = num; i > 0; i--){
    
        removeRoot(a,i);
        printArray(a,10);
    }

}
void removeRoot(int *a,int num)
{

    swap(&a[0],&a[num - 1]);
    buildHeap(a,num - 1);
}


void buildHeap(int *a,int num)
{
    int i,j,k;
    int pos;
    int p;

    for(i=1; i<num; i++){
        pos = i;
        p = PARENT(pos);
        while(a[pos] > a[p]){
            swap(&a[pos],&a[p]);
            pos = p;
            p = PARENT(pos);
        }
    }    
}


void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;


}

void mergeSort(int *a,int s,int e)
{
    if(s == e)
        return;

    int middle = (e + s) / 2;
     
    if(middle < 0){
        printf("s [%d] e [%d]\n",s,e);
        exit(0);
    }

    if(e - s == 1){

        if(a[s] > a[e]){
            int temp = a[s];
            a[s] = a[e];
            a[e] = temp;
        }

        return;
    }

    printf("[%d] [%d] | [%d] [%d]\n",s,middle,middle+ 1, e);

    mergeSort(a,s,middle);
    mergeSort(a,middle + 1,e);

    int w[e - s + 1];
    int i,j,k;
    i = s;
    j = middle + 1;
    k=0;

    while(i <= middle && j <= e){
        if(a[i] < a[j]){
            w[k] = a[i];
            i++;
        }else{
            w[k] = a[j];
            j++;
        }

        k++;
    } 

    while(i <= middle){
        w[k] = a[i];
        i++;
        k++;
    }

    while(j <= e){
        w[k] = a[j];
        j++;
        k++;
    }
    
 
    k--;

    while(k >= 0){
        a[s + k] = w[k];
        k--;
    }

}

void insertionSort(int *a,int num)
{
    int i,j;

    //for each elment
    for(i=1; i<num;i++){

        j = i;
        while(j > 0  && a[j] < a[j - 1]){
            int temp = a[j];
            a[j] = a[j - 1];
            a[j - 1] = temp;
            j--; 
        }
    }
}


void bubbleSort(int *a,int num)
{
    int i,j;
    int flag;

    for(i=(num - 1); i >= 0; i--){
        flag = 1;
        for(j=0; j < i;j++){
            if(a[j] > a[j+1]){
                flag = 0;                
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
        if(flag == 1)
            break;
    }

} 
void printArray(int *a, int num)
{
    int i;

    for(i=0;i<num;i++)
        printf("%d ",a[i]);

    printf("\n");
} 
