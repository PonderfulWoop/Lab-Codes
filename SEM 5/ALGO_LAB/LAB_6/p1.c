#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

typedef struct Node Node;

Node* getNode(int data){
    Node* t = (Node*)malloc(sizeof(Node));
    t->data = data;
    t->left = t->right = NULL;

    return t;
}

int count = 0;

int getNum(Node* t){
	count++;
    if(t == NULL)
        return 0;
    else{
        return 1 + getNum(t->left) + getNum(t->right);
    }
}

int main(){
    Node* root = getNode(5);
    root->right = getNode(10);
    root->left = getNode(3);
    root->right->left = getNode(7);
    root->right->right = getNode(12);
    root->left->right = getNode(4);
    root->left->left = getNode(2);
    root->right->right->left = getNode(23);
    root->right->right->right = getNode(45);
    root->right->right->left->right = getNode(40);
    root->right->right->left->left = getNode(40);
    root->right->right->left->right->right = getNode(40);
    root->right->right->left->right->left = getNode(40);
    root->right->right->left->right->right->left = getNode(40);
    root->right->right->left->right->right->right = getNode(40);
    root->right->right->left->right->left->right = getNode(40);
    root->right->right->left->right->left->left = getNode(40);
    root->right->right->left->right->left->right->left = getNode(40);
    root->right->right->left->right->left->right->right = getNode(40);
    root->right->right->left->right->left->right->right->left = getNode(40);

    printf("Number of nodes: %d\n", getNum(root));
    printf("Number of function calls: %d\n", count);

}
