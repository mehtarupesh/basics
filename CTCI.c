#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define EAST 0
#define WEST 1
#define NORTH 2
#define SOUTH 3

#define STR "0123456789abcdefghijklmnopqrstuvwxyz"

int t[9] = {-1,-1,-1,-1,-1,-1,-1,-1,-1};
int check(int i);
void queen(int i);
void print_solution();

//crap
void print_helical(int a[4][4]);
int arr[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

void reverse_string(char *string,int index);

void swap(char *x,char *y);
void permute(char *a,int start,int end);

void decimalToBase(int dec,int base);

int num_solutions=0;
void main(){


    int x;
    
    for(x = 0; x < 1000000;x++){
        printf("%d...\r\b",x);
    }
    return;    

    int i,j,k;
    int m=2,n=2,l=3;

    int a[2][3] = {{1,2,3},{4,5,6}}; //2 x 3
    int b[3][2] = {{1,2},{3,4},{5,6}}; // 3 x 2
    int c[2][2]; // 2 x 2

    for(i=0;i<m;i++)
        for(j=0;j<n;j++){
        
            c[i][j] = 0;
            for(k=0;k<l;k++)
                c[i][j] += a[i][k] * b[k][j];
        }    

    return;

    decimalToBase(50,2);
    decimalToBase(50,16);
    decimalToBase(50,8);

    return;

    char str[] = "ABC";
    permute(str,0,2);

    return;

    char val[] = "This is the life";
    printf("Before : [%s] length [%d]\n",val,(int)strlen(val));
    reverse_string(val,0);
    printf("After : [%s]\n",val);

    return; 
    print_helical(arr);

    return;
    print_solution();
    queen(1);
    printf("num_sol = [%d]\n",num_solutions);

}

void decimalToBase(int dec,int base)
{
    printf("Covert from decimal [%d] to base [%d]\n",dec,base);
    int i,m,n;char result[100];
    m = dec;
    i = 0;

    while(m){
        n = m % base;
        result[i] = STR[n];
        m = m / base;        
        i++;
    }
    
    i--;
    while(i >= 0){
        printf("%c",result[i]);
        i--;
    }
    printf("\n");
}
void swap(char *x,char *y)
{
    char temp = *x;
    *x = *y;
    *y = temp;

}

void permute(char *a,int start,int end)
{

    int i;

    if(start == end)
        printf("[%s]\n",a);
    else{

        for(i=start;i<=end;i++){

            printf("[%c] <==> [%c]\n",*(a + start),*(a + i));
            swap(a + start,a + i);
            permute(a,start+1,end);
            swap(a + start,a + i);
        }

    }

}
void reverse_string(char *string,int index){

    char *ch = string;
    char val1,val2;

    if(index == (strlen(string)/2))
        return;

    val1 = *(ch + index);
    ch = ch + (strlen(string) - index - 1);
    val2 = *ch;
    
    //    printf("[%d] [%c]\n",index,val);

    string[index] = val2;
    string[strlen(string) - 1 - index] = val1;
    reverse_string(string,(index + 1));


}
void print_helical(int a[4][4])
{

    int direction = EAST;
    int i=0;
    int j=0;

    int x = 1;
    int y = 1;

    while(1){

        switch(direction){
            case  EAST : x = 0;y = 1;
                         if((i + j) == 3){
                             direction = SOUTH;
                             x = 1; y = 0;
                         }

                         break;            
            case   WEST : x = 0;y = -1;
                          if((i + j) == 3){
                              direction = NORTH;
                              x = -1; y = 0;
                          }


                          break;            

            case  NORTH : x = -1;y = 0;
                          if((i - j) == 1){
                              direction = EAST;
                              x = 0; y = 1;
                          }
                          break;            

            case SOUTH : x = 1 ;y = 0;
                         if((i - j) == 0){
                             direction = WEST;
                             x = 0; y = -1;
                         }
                         break;            

        }

        if(i == 0 && j == 0)
            printf("[%d][%d] = [%d]\n",i,j,a[i][j]);

        i = i + x;
        j = j + y;

        printf("[%d][%d] = [%d]\n",i,j,a[i][j]);
        if(i == 2 && j == 1)
            break;


    }
}



void queen(int i)
{

    for(t[i] = 1; t[i] <= 8 ; t[i]++){

        if(check(i)){

            if(i == 8){
                num_solutions++;
                int temp;
                for(temp=1;temp<=8;temp++)
                    printf("[%d] ",t[temp]);

                printf("\n"); 
                // print_solution();
                // exit(0);
            }
            else{
                queen(i + 1);
            }
        }

    }
}

int check(int i)
{

    int j =1;

    while( t[i] != t[j] && abs(t[i] - t[j]) != (i - j) && j < 8)j++;

    return ((i == j) ? 1 : 0);
}

void print_solution(){

    int i=1;
    for(i = 1; i <= 8;i++)
        printf("t[%d] = %d\n",i,t[i]);

    printf("----------------\n");

}
