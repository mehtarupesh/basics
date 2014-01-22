#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

#define TRUE 1
#define FALSE 0

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
int minValue(node_t* tree);
void printTree(node_t* tree);
void printPostOrder(node_t* tree);
int hasPathSum(node_t* tree, int sum);
void printPaths(node_t* tree);
void mirror(node_t* tree);
void doubleTree(node_t* tree);
int sameTree(node_t* a,node_t* b);
int countTrees(int num);
int isBST(node_t *tree);
int isBST2(node_t *tree);
int isBSTRecur(node_t* tree,int min,int max);

void main() {

    node_t* tree = insert(tree,1);
    tree = insert(tree,2);
    tree = insert(tree,3);
    tree = insert(tree,4);
    tree = insert(tree,-3);

    printTree(tree);
    printf("\n");

    printf("MaxDepth [%d]\n",maxDepth(tree));
    printf("Size [%d]\n",size(tree));
    printf("minValue [%d]\n",minValue(tree));
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


int minValue(node_t* tree){

    if(tree->left != NULL)
        return minValue(tree->left);

    return tree->data;
}
