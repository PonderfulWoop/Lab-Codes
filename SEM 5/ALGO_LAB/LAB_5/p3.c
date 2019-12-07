#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* right;
    struct Node* left;
};

typedef struct Node Node;

Node* getNode(int val){
    Node* t = (Node*)malloc(sizeof(Node));
    t->data = val;
    t->right = NULL;
    t->left = NULL;

    return t;
}
int height(Node* node){
    if(node == NULL)
        return 0;
    
    return 1 + max(height(node->left), height(node->right));
}
int max(int a, int b){
    return (a>b) ? a:b;
}

int diameter(Node * root){
    if(root == NULL)
        return 0;
    
    int l_height = height(root->left);
    int r_height = height(root->right);

    int l_diameter = diameter(root->left);
    int r_diameter = diameter(root->right);

    return max(l_height+r_height+1, max(l_diameter, r_diameter));
}

int main(){
    Node *root = getNode(1); 
    root->left        = getNode(2); 
    root->right       = getNode(3); 
    root->left->left  = getNode(4); 
    root->left->right = getNode(5);

    printf("Diameter = %d\n", diameter(root));
}