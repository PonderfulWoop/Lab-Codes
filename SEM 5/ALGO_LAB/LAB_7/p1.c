#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

typedef struct Node Node;

int max(int a, int b){
    return (a>b)?a:b;
}

Node* getNode(int data){
    Node *t = (Node*)malloc(sizeof(Node));
    t->data = data;
    t->right = t->left = NULL;

    return t;
}

int getHeight(Node* root){
    if(root == NULL)
        return 0;
    else
        return 1 + max(getHeight(root->left), getHeight(root->right));
}

void findBF(Node* root){
    if(root != NULL){
        findBF(root->left);
        printf("BF for %d: %d\n", root->data, (getHeight(root->left) - getHeight(root->right)));
        findBF(root->right);
    }
}

int main(){
    Node* root = getNode(4);
    root->right = getNode(6);
    root->left = getNode(2);
    root->left->right = getNode(3);
    root->right->right = getNode(7);
    root->right->left = getNode(5);

    /*
          4
         / \
        2   6
         \   /\
          3 5 7
    */
   findBF(root);
}