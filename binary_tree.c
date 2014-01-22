#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

#define TRUE 1
#define FALSE 0

#define MIN(a,b)    (a < b ? a : b)
#define MAX(a,b)    (a > b ? a : b)

#define INT_MIN_VAL (1 << 31)
#define INT_MAX_VAL (~(1 << 31))
typedef struct node{

    int data;
    struct node *left;
    struct node *right;


} node_t;

static node_t* newNode(int data);
static int lookup(node_t* tree,int target);
static node_t* insert(node_t* tree,int data);

node_t* build123();
int size(node_t* tree);
int maxDepth(node_t* tree);
int minValueBST(node_t* tree);
int minValue(node_t* tree);
int maxValueBST(node_t* tree);
int maxValue(node_t* tree);
void printTree(node_t* tree);
void printTreeInOrder(node_t* tree);
void printPostOrder(node_t* tree);
int hasPathSum(node_t* tree, int sum);
void printPaths(node_t* tree);
void printPathsRecur(node_t *tree,int path[],int pathLen);

void mirror(node_t* tree);
void doubleTree(node_t* tree);
int sameTree(node_t* a,node_t* b);
int countTrees(int num);
int isBST(node_t *tree);
int isBST2(node_t *tree);
int isBSTRecur(node_t* tree,int min,int max);

int sequence[] = {3,1,5,0,2,4,6,7};
int num = 8;//5;
int sum = 21;

void main() {

    int i;
    node_t* tree=NULL;

    for(i=0;i<num;i++)
        tree =insert(tree,sequence[i]);
 
/*   
    tree = insert(tree,4);
    tree = insert(tree,2);
    tree = insert(tree,5);
    tree = insert(tree,1);
    tree = insert(tree,3);
  */ 

    printTree(tree);
    printf("\n");
    printTreeInOrder(tree);
    printf("\n");
    printPostOrder(tree);
    printf("\n");
    printPaths(tree);
    printf("\n");

    mirror(tree);
    printTree(tree);
    printf("\n");
    printPaths(tree);
    printf("\n");

    doubleTree(tree);
    printTree(tree);
    printf("\n");
    printPaths(tree);
    printf("\n");
    

    printf("SizeofInt [%lu]\n",sizeof(int));
    printf("MaxDepth [%d]\n",maxDepth(tree));
    printf("Size [%d]\n",size(tree));
    printf("minValueBST [%d]\n",minValueBST(tree));
    printf("minValue [%d]\n",minValue(tree));
    printf("hasPathSum (%d) [%d]\n",sum,hasPathSum(tree,sum));
    printf("SameTree [%d]\n",sameTree(tree,tree->left));
}

static node_t* newNode(int data){
    node_t * new = malloc(sizeof(node_t));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

static int lookup(node_t* tree,int target){

    if(tree == NULL)
        return FALSE;

    if(target == tree->data)
        return TRUE;

    if(target <= tree->data)
        return (lookup(tree->left,target));
    else
        return (lookup(tree->right,target));

}

static node_t* insert(node_t* tree,int data){

    if(tree == NULL){
        return newNode(data);
    }

    if(data <= tree->data){
        tree->left = insert(tree->left,data);
    }
    else
        tree->right = insert(tree->right,data);

    return tree;

}

int size(node_t* tree){

    if(tree == NULL)
        return 0;

    return(1 + size(tree->left) + size(tree->right));

}


int maxDepth(node_t* tree){
    
    if(tree == NULL)
        return 0;

    int l,r;
    return (1 + ( ( (l=maxDepth(tree->left)) >  (r=maxDepth(tree->right) ) ? l : r ) ) );

}

/*for binary search trees*/
int minValueBST(node_t* tree){

    if(tree->left != NULL)
        return minValueBST(tree->left);

    return tree->data;
}

/*for binary trees*/
int minValue(node_t* tree){

    int l,r;

    l = r = INT_MAX_VAL;

    if(tree->left != NULL)
        l = minValue(tree->left);

    if(tree->right != NULL)
        r = minValue(tree->right);

    return MIN(tree->data,MIN(l,r));
}

/*for binary search trees*/
int maxValueBST(node_t* tree){

    if(tree->left != NULL)
        return maxValueBST(tree->left);

    return tree->data;
}

/*for binary trees*/
int maxValue(node_t* tree){

    int l,r;

    l = r = INT_MIN_VAL;

    if(tree->left != NULL)
        l = maxValue(tree->left);

    if(tree->right != NULL)
        r = maxValue(tree->right);

    return MAX(tree->data,MAX(l,r));
}

void printTree(node_t* tree){

    if(tree == NULL)
        return;

    printf("[%d] ",tree->data);
    printf("{L");
    printTree(tree->left);
    printf(" R");
    printTree(tree->right);
    printf("}"); 

}

void printTreeInOrder(node_t* tree){

    if(tree == NULL)
        return;

    //recurse left
    printTreeInOrder(tree->left);
    //print data
    printf(" [%d] ",tree->data);
    //recurse right
    printTreeInOrder(tree->right);
 
}

void printPostOrder(node_t* tree){

    if(tree == NULL)
        return;

    //recurse left
    printPostOrder(tree->left);
    //recurse right
    printPostOrder(tree->right);
    //print data
    printf(" [%d] ",tree->data);
    
}

int hasPathSum(node_t* tree, int sum){

    if(tree == NULL)
        return (sum == 0);

    sum = sum - tree->data;    
    
    return (hasPathSum(tree->left,sum) || hasPathSum(tree->right,sum));

}

void printPaths(node_t* tree){

    int len = size(tree);
    int path[len];
    
    printPathsRecur(tree,path,0); 

}


void printPathsRecur(node_t *tree,int path[],int pathLen)
{

    if(tree == NULL)
        return;

    int i;
    if((tree->left == NULL) && (tree->right == NULL)){

        printf("Path (len = %d) : ",pathLen + 1);
        for(i=0;i<pathLen;i++){
            printf("[%d] ",path[i]);
        }
        printf(" [%d]\n",tree->data);
    }else{

    path[pathLen] = tree->data;
    pathLen++;
 
    printPathsRecur(tree->left,path,pathLen);
    printPathsRecur(tree->right,path,pathLen);
    }
}

void mirror(node_t* tree)
{

    if(tree == NULL)
        return;

    node_t* temp;

    temp = tree->left;
    tree->left = tree->right;
    tree->right = temp;

    mirror(tree->left);
    mirror(tree->right);
}

void doubleTree(node_t* tree)
{

    if(tree == NULL)
        return;

    node_t *temp;
    node_t *dup = newNode(tree->data);
    temp = tree->left;
    
    tree->left = dup;
    dup->left = temp;

    doubleTree(temp);
    doubleTree(tree->right);
}

int sameTree(node_t* a,node_t* b){

    if(a == NULL && b == NULL)
        return TRUE;

    if(a == NULL || b == NULL)
        return FALSE;

    if(a->data == b->data)
        return (sameTree(a->left,b->left) && sameTree(a->right,b->right));
    else
        return FALSE;
}

//didnt understand
int countTrees(int num);


int isBST(node_t *tree)
{
    if(tree == NULL)
        return TRUE;
    
    if((maxValueBST(tree->left) <= tree->data) && (tree->data < minValueBST(tree->right)))
        return (isBST(tree->left) && isBST(tree->right)); 
    else
        return FALSE;
}

int isBST2(node_t *tree);
int isBSTRecur(node_t* tree,int min,int max);
