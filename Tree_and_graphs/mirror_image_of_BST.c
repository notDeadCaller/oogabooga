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

struct Node* insert(struct Node* node, int data) {
    if (node == NULL) return newNode(data);
    if (data < node->data) node->left = insert(node->left, data);
    else if (data > node->data) node->right = insert(node->right, data);
    return node;
}

struct Node* mirror(struct Node* root) {
    if (root == NULL) return NULL;

    struct Node* left = mirror(root->left);
    struct Node* right = mirror(root->right);

    root->left = right;
    root->right = left;

    return root;
}

void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main() {
    struct Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);

    printf("Original In-order Traversal: ");
    inOrderTraversal(root);
    printf("\n");
    
    root = mirror(root);

    printf("Mirror In-order Traversal (Should be reversed): ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
