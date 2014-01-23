#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{

    int data;
    struct node *next;
    struct node *prev;


} node_t;

//add,delete,find,replace
#define  node_add(head,element) do{ \
    node_t *trav;\
    if(head == NULL){ \
        head = element;\
        head->next = NULL;\
    }\
    else{\
        trav = head;\
        while(trav->next != NULL){\
            trav = trav->next;\
        } \
        trav->next = element;\
    }\
}while(false)

node_t *node_create(int data_val);

//by value
bool node_delete(node_t** head,int val);
bool list_delete(node_t** head);
node_t* node_find(node_t* head,int val);
node_t* node_get_index(node_t* head,int index);
int pop_top(node_t** head);
void insert_n(node_t** head,int index,int data);
void sorted_insert(node_t **head,node_t *new);
void sort_list(node_t **head);
void front_back_split(node_t* source, node_t** frontRef, node_t** backRef);
void front_back_split2(node_t* source, node_t** frontRef, node_t** backRef);
int move_node(node_t** dest,node_t** src);
void alternating_split(node_t* source, node_t** frontRef, node_t** backRef);
node_t* shuffle_merge(node_t* a,node_t* b);
node_t* sorted_merge(node_t *a,node_t* b);

void merge_sort(node_t **list);
//debugging
void print_list(node_t *hol);

void main(){

    node_t *hol = NULL;
    node_t *node1,*node2,*node3;
    node_t *node4;
    node_t *front;
    node_t *back;

    insert_n(&hol,0,4);
    print_list(hol);
    insert_n(&hol,1,-2);
    print_list(hol);
    insert_n(&hol,2,5);
    print_list(hol);
    insert_n(&hol,0,33);
    print_list(hol);
    insert_n(&hol,1,23);
    print_list(hol);

//    sort_list(&hol);
//    print_list(hol);

    merge_sort(&hol);
    print_list(hol);    

    return;

    alternating_split(hol,&front,&back);
    print_list(front);
    print_list(back);
    //print_list(shuffle_merge(front,back));
    print_list(sorted_merge(front,back));    

    return;

    front_back_split2(hol,&front,&back); 
    print_list(front);
    print_list(back);

    move_node(&back,&front);
    print_list(front);
    print_list(back);


    return;

    node1 = node_create(1);
    node2 = node_create(4);
    node3 = node_create(-5);

    node_add(hol,node1);
    node_add(hol,node2);
    node_add(hol,node3);

    int i;
    int array[] = {4,1,-5,2};
    for(i=0;i<4;i++){
        //	node4 = node_get_index(hol,i);
        node4 = node_find(hol,array[i]);
        if(node4)
            printf("Val [%d] = [%d]\n",array[i],node4->data);
        else
            printf("Cannot find value [%d]\n",array[i]);	
    }


    print_list(hol);

    printf("popping : [%d]\n",pop_top(&hol));
    //node_delete(&hol,1);
    print_list(hol);

    printf("popping : [%d]\n",pop_top(&hol));
    //node_delete(&hol,-5);
    print_list(hol);

    printf("popping : [%d]\n",pop_top(&hol));
    //node_delete(&hol,4);
    print_list(hol);

}

void print_list(node_t *head){

    while(head != NULL){
        printf("[%d]->",head->data);
        head = head->next;
    }
    printf("[NULL]\n");

}

node_t *node_create(int val){

    node_t *n = malloc(sizeof(node_t));
    n->data = val;
    n->next = NULL;
}


bool node_delete(node_t** head,int val){

    node_t *hol = *head;
    node_t *trav = hol;
    node_t *t = hol;
    int i=0;
    while(trav != NULL){
        if(trav->data == val){
            printf("Found [%d] at index [%d]\n",val,i);
            printf("deleting...\n");

            if(i == 0){
                *head = (*head)->next;
                free(trav);
                return true;
            }else{
                t->next = trav->next;
                free(trav);
                return true;	
            }

        }
        t = trav;
        trav = trav->next;
        i++;

    }
    return false;
}


bool list_delete(node_t** head);

node_t* node_find(node_t* head,int val){

    node_t *trav = head;

    while(trav != NULL){

        if(trav->data == val){

            printf("Found [%d]\n",val);
            return trav;
        }
        trav = trav->next;
    }

}

node_t* node_get_index(node_t* head,int index){

    node_t *trav = head;
    int i=0;

    while(trav != NULL){

        if(i == index){

            printf("Found at index [%d] = [%d]\n",index,trav->data);
            return trav;
        }
        i++;
        trav = trav->next;
    }
    return NULL;
}

int pop_top(node_t** head){

    node_t *n = *head;
    int val = 255;

    if(n != NULL){
        val = n->data;

        *head = (*head)->next;

        free(n);
    }
    return val;
}

void insert_n(node_t** head,int index,int data){

    node_t *hol = *head;
    node_t *trav = hol;
    node_t *prev = hol;
    node_t *new ;
    int i=0;

    for(;trav != NULL;prev = trav,trav = trav->next,i++){

        //slide over the point at index
        if(i == index){

            printf("Sliding over at index [%d]\n",i);	
            new = node_create(data);	

            if(0 == index){
                new->next = *head;
                *head = new;
            }
            else{
                prev->next = new;
                new->next = trav; 	
            }

            return;
        }

    } 

    //insert first time at index
    if(i == index){
        printf("Adding first time at index [%d]\n",index);						
        new = node_create(data);	
        if(0 == index){
            *head = new;
        }else{
            prev->next = new;
        }
        return;		
    }

    printf("Invalid index insert request! [%d]\n",index);

}

//in a sorted list, puts new node to maintain increasing order of data
void sorted_insert(node_t **head,node_t *new){

    node_t *hol = *head;
    node_t *trav = hol;
    node_t *prev = hol;	

    int i=0;
    for(;trav != NULL; prev = trav,trav = trav->next,i++){
        if(new->data < trav->data){
            if(0 == i){
                new->next = trav;
                *head = new;	
            }else{
                new->next = trav;
                prev->next = new;
            }	
            return;
        }
    }

    //empty list or largest number
    if(0 == i){
        new->next = NULL;	
        *head = new;
    }
    else{
        new->next = NULL;	
        prev->next = new;
    }

    return;	

}

/*sort list in ascending order*/
void sort_list(node_t **head)
{
    node_t *hol = *head;
    node_t *trav = hol;
    node_t *new_list = NULL;
    node_t *n;

    printf("Sorting List...\n");
    while(trav != NULL){

        n = trav;
        trav = trav->next;

        //remove first node
        n->next = NULL;
        sorted_insert(&new_list,n);

    }

    *head = new_list;
}

int count_elements(node_t* list){
    int n=0;
    node_t* trav = list;

    while(trav != NULL){
        n++;
        trav = trav->next;
    }
    return n;

}

void front_back_split(node_t* source, node_t** frontRef, node_t** backRef)
{
    node_t *front = *frontRef = NULL;
    node_t *back = *backRef = NULL;
    node_t *trav = source;
    node_t *new;
    int n = count_elements(trav);
    int i,front_half;

    front_half = n/2 + ((n % 2) ? 1: 0);

    printf("Front Back Split, front = [%d] , back = [%d]\n",front_half,(n - front_half));

    print_list(trav);
    /*counting method*/ 
    for(i=0;i < n;i++){

        new = trav;
        trav = trav->next;
        new->next = NULL;

        if(i < front_half){
            //add to frontlist
            sorted_insert(frontRef,new);
        }else
        {
            //add to backlist
            sorted_insert(backRef,new);
        }
    }
}


void front_back_split2(node_t* source, node_t** frontRef, node_t** backRef)
{
    node_t *front = *frontRef = NULL;
    node_t *back = *backRef = NULL;
    node_t *trav = source;
    node_t *new;

    node_t *slow = source;
    node_t *fast = source;

    if(source != NULL)
        fast = fast->next;

    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }     
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL; 
}

int  move_node(node_t** dest,node_t** src)
{

    node_t *temp = *src;

    if(temp == NULL)
        return 0;

    *src = (*src)->next;

    temp->next = *dest;
    *dest = temp;

    return 1;
}

int  move_node_tail(node_t** dest,node_t** src)
{

    node_t *temp = *src;
    node_t *target = *dest;

    if(temp == NULL)
        return 0;

    *src = (*src)->next;
   
    //make ready to add to tail 
    temp->next = NULL;

    //add to tail
    if(target == NULL)
        *dest = temp;
    else{ 

    while(target->next != NULL)
        target = target->next;

    }

    target->next = temp;

    return 1;
}

void alternating_split(node_t* source, node_t** frontRef, node_t** backRef)
{
    node_t* trav = source;
    node_t* temp;
    *frontRef = *backRef = NULL;
    int alternate = 1;

    while(trav != NULL){

        if(alternate)
            move_node(frontRef,&trav);
        else
            move_node(backRef,&trav);

        alternate = !alternate;       

    }    
}


node_t* shuffle_merge(node_t* a,node_t* b)
{
    node_t* final = NULL;
 
    int alternate = 1;

    while(1){

        if(alternate){
            if(!move_node(&final,&a)){
                while(move_node(&final,&b));
                return final;
            }
        }
        else{
            if(!move_node(&final,&b)){
                while(move_node(&final,&a));
                return final;
            }
        }
        alternate = !alternate;
    }


}


node_t* sorted_merge(node_t *a,node_t* b)
{
    node_t *result=NULL;
    
    if(a == NULL)
        return b;
    if(b == NULL)
        return a; 

    if(a->data <= b->data){
        result = a;
        result->next = sorted_merge(a->next,b);
    }else{
        result = b;
        result->next = sorted_merge(a,b->next);
    }    

    return result;
}
    

void merge_sort(node_t **list)
{
    node_t *a = NULL;
    node_t *b = NULL;
    node_t *temp = *list;

    if((temp == NULL) || (temp->next == NULL))
        return;

    front_back_split(*list,&a,&b);
    merge_sort(&a);
    merge_sort(&b);
    
    *list = sorted_merge(a,b);  

}

