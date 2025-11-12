#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int isFullBinaryTree(struct Node* root) {
    if (root == NULL) return 1;
    if (root->left == NULL && root->right == NULL) return 1;
    if (root->left && root->right) {
        return (isFullBinaryTree(root->left) && isFullBinaryTree(root->right));
    }
    return 0;
}

int countNodes(struct Node* root) {
    if (root == NULL) return 0;
    return (1 + countNodes(root->left) + countNodes(root->right));
}

int isCompleteBinaryTree(struct Node* root, int index, int nodeCount) {
    if (root == NULL) return 1;
    if (index >= nodeCount) return 0;
    
    return (isCompleteBinaryTree(root->left, 2 * index + 1, nodeCount) &&
            isCompleteBinaryTree(root->right, 2 * index + 2, nodeCount));
}

int main() {
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    int nodeCount = countNodes(root);
    
    printf("Is the tree Full? %s\n", isFullBinaryTree(root) ? "Yes" : "No");
    printf("Is the tree Complete? %s\n", isCompleteBinaryTree(root, 0, nodeCount) ? "Yes" : "No");

    return 0;
}
