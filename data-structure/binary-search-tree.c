#include <stdio.h>
#include <stdlib.h>

// it creates a complete binary tree

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;

void printTree(Node *root, int space)
{
    if (root == NULL)
        return;

    space += 10;

    printTree(root->right, space);

    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    printTree(root->left, space);
}

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = newNode->parent = NULL;
    return newNode;
}

void insert(Node **root, int data)
{
    Node *prev = *root;
    Node *pointer = NULL;

    Node *newNode = createNode(data);

    while (prev != NULL)
    {
        pointer = prev;
        if (newNode->data < prev->data)
            prev = prev->left;
        else
            prev = prev->right;
    }

    if (pointer == NULL)
        *root = newNode;
    else if (newNode->data < pointer->data)
        pointer->left = newNode;
    else
        pointer->right = newNode;

    newNode->parent = pointer;
}

void inorderTraversal(Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

Node *search(Node *p, int key)
{
    if (p == NULL || key == p->data)
        return p;
    if (key < p->data)
        return search(p->left, key);
    else
        return search(p->right, key);
}

Node *minimum(Node *root)
{
    Node *p = root;
    while (p->left != NULL)
        p = p->left;
    return p;
}

Node *maximum(Node *root)
{
    Node *p = root;
    while (p->right != NULL)
        p = p->right;
    return p;
}

void transplant(Node **root, Node *u, Node *v)
{
    if (u->parent == NULL)
        (*root) = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;

    if (v != NULL)
        v->parent = u->parent;
}

void delete(Node **root, int data)
{
    Node *z = search((*root), data);
    if (z->left == NULL)
        transplant(root, z, z->right);
    else if (z->right == NULL)
        transplant(root, z, z->left);
    else
    {
        Node *y = minimum(z->right);
        if (y != z->right)
        {
            transplant(root, y, y->right);
            y->right = z->right;
            z->right->parent = y;
        }
        transplant(root, z, y);
        y->left = z->left;
        y->left->parent = y;
    }

    free(z);
}

int main()
{
    int arr[] = {8, 3, 10, 1, 4, 9, 11, 6, 5, 7, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *root = NULL;

    for (int i = 0; i < n; ++i)
        insert(&root, arr[i]);

    printTree(root, 0);

    delete (&root, 8);

    printf("----------------\n");
    printTree(root, 0);

    printf("Inorder traversal result: ");
    inorderTraversal(root);
    printf("\n");

    printf("search 4 : %d\n", search(root, 4)->data);
    printf("minimum : %d\n", minimum(root)->data);
    printf("maximum : %d\n", maximum(root)->data);

    return 0;
}
