#include <stdio.h>
#include <stdlib.h>

#define THREAD_TRUE 1
#define THREAD_FALSE 0

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    int left_thread;
    int right_thread;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->left_thread = THREAD_FALSE;
    node->right_thread = THREAD_FALSE;
    return node;
}

struct Node* inorderSuccessor(struct Node* ptr) {
    if (ptr->right_thread == THREAD_TRUE) return ptr->right;
    ptr = ptr->right;
    while (ptr->left_thread == THREAD_FALSE) ptr = ptr->left;
    return ptr;
}

void inorderThreadedTraversal(struct Node* root) {
    if (root == NULL) return;

    struct Node* ptr = root;
    while (ptr->left_thread == THREAD_FALSE) ptr = ptr->left;

    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = inorderSuccessor(ptr);
    }
    printf("\n");
}

int main() {
    struct Node *root = newNode(6);
    root->left = newNode(3);
    root->right = newNode(9);
    root->left->left = newNode(1);
    root->left->right = newNode(5);

    // Manually setting threads for demonstration (1, 3, 5, 6, 9)
    root->left->left->right = root->left; 
    root->left->left->right_thread = THREAD_TRUE;
    
    root->left->right->right = root; 
    root->left->right->right_thread = THREAD_TRUE;

    // This demonstrates the usage of the inorderSuccessor logic
    printf("Inorder Traversal of Two-Way Threaded Tree: ");
    inorderThreadedTraversal(root);
    
    return 0;
}
