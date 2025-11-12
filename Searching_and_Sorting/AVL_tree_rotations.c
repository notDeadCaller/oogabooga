#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};

int height(struct Node *N) {
    if (N == NULL) return 0;
    return N->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

// Right rotation (RR imbalance)
struct Node *rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Left rotation (LL imbalance)
struct Node *leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Get Balance factor
int getBalance(struct Node *N) {
    if (N == NULL) return 0;
    return height(N->left) - height(N->right);
}

struct Node* insert(struct Node* node, int data) {
    if (node == NULL) return newNode(data);

    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    } else {
        return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    // LL Case (Left Left)
    if (balance > 1 && data < node->left->data) {
        printf("Applying LL Rotation at node %d\n", node->data);
        return rightRotate(node);
    }

    // RR Case (Right Right)
    if (balance < -1 && data > node->right->data) {
        printf("Applying RR Rotation at node %d\n", node->data);
        return leftRotate(node);
    }

    // LR Case (Left Right)
    if (balance > 1 && data > node->left->data) {
        printf("Applying LR Rotation at node %d\n", node->data);
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL Case (Right Left)
    if (balance < -1 && data < node->right->data) {
        printf("Applying RL Rotation at node %d\n", node->data);
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void preOrder(struct Node *root) {
    if (root != NULL) {
        printf("%d (B:%d) ", root->data, getBalance(root));
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    struct Node *root = NULL;

    // RR Case Demo (Insert: 10, 20, 30)
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    printf("Preorder after RR rotation (Root should be 20): ");
    preOrder(root);
    printf("\n\n");

    // Resetting for next demo is complex, so we'll just demonstrate rotations.
    // The provided function logic implements all four rotations (LL, RR, LR, RL) dynamically.
    
    return 0;
}
