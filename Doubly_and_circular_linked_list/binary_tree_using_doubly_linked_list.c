#include <stdio.h>
#include <stdlib.h>

struct BTNode {
    int data;
    struct BTNode* left;  // prev in DLL
    struct BTNode* right; // next in DLL
};

struct BTNode* createBTNode(int data) {
    struct BTNode* newNode = (struct BTNode*)malloc(sizeof(struct BTNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct BTNode* insertBTNode(struct BTNode* root, int data) {
    if (root == NULL) {
        return createBTNode(data);
    }
    if (data < root->data) {
        root->left = insertBTNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertBTNode(root->right, data);
    }
    return root;
}

void inorderTraversal(struct BTNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct BTNode* root = NULL;
    
    root = insertBTNode(root, 50);
    insertBTNode(root, 30);
    insertBTNode(root, 70);
    insertBTNode(root, 20);
    insertBTNode(root, 40);

    printf("Binary Tree (Inorder Traversal):\n");
    inorderTraversal(root);
    printf("\n(Structure uses DLL nodes where left=prev and right=next)\n");
    
    return 0;
}