#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void printTree(struct Node* root) {
    if (root != NULL) {
        printf("Node: %d (Left: %s, Right: %s)\n", 
               root->data, 
               root->left ? "Yes" : "No", 
               root->right ? "Yes" : "No");
        printTree(root->left);
        printTree(root->right);
    }
}

int main() {
    struct Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    
    printf("Binary Tree Structure (Pre-order format):\n");
    printTree(root);

    return 0;
}
