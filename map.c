#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *map[] = {"ABC","DEF","GHI","JKL"};

char str1[] = "112";
#define INVALID_CHAR    '^'

void permuteNumToChar(char *str,int index,char *num);
void main()
{

    char num[strlen(str1) + 1];
    int i,j;

    for(i=0;i<strlen(num);i++)
        num[i] = INVALID_CHAR;

    printf("Starting...\n");
    for(i = 0; i < 4; i++){
        for(j = 0; j < strlen(map[i]); j++)
            printf("%c",map[i][j]);
        printf("\n");
    }    

    permuteNumToChar(str1,0,num);

}

void permuteNumToChar(char *str,int index,char *num)
{
    int i,j,k;
    char *c;
    i = index;


//    printf("index [%d]\n",index);

    if(index == strlen(str)){
        printf("[%s]\n",num);
        return;
    }

    int val = str[i] - '0';
    int check = 0;    

//    printf("Val [%d]\n",val);

    //check if this val has been used before
    for(j=0; j < strlen(map[val]);j++)
        if((c = strchr(num,map[val][j])) != NULL){
            check = 1;
//            printf("Found [%c]\n",*c);
            break;
        }

    if(!check){
        for(k=0; k< strlen(map[val]); k++){
            num[i] = map[val][k];
            permuteNumToChar(str,index + 1,num);
        }
    }else{
        num[i] = *c;
        permuteNumToChar(str,index + 1,num);

    }
    
    num[index] = INVALID_CHAR;

}
