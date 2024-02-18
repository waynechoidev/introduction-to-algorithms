#include <stdio.h>
#include <stdlib.h>

// it creates a complete binary tree

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void insert(Node** root, int data) {
    if(*root == NULL)
        *root = createNode(data);
    else if((*root)->left == NULL)
        (*root)->left = createNode(data);
    else if((*root)->right == NULL)
        (*root)->right = createNode(data);
    else
        insert(&((*root)->left), data);

}

void preorderTraversal(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void postorderTraversal(Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    Node* root = NULL;
    insert(&root, 1);
    insert(&root, 2);
    insert(&root, 3);
    insert(&root, 4);
    insert(&root, 5);

    printf("Preorder traversal result: ");
    preorderTraversal(root);
    printf("\n");

    printf("Inorder traversal result: ");
    inorderTraversal(root);
    printf("\n");

    printf("Postorder traversal result: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
