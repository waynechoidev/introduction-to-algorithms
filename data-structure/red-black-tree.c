#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    bool isRed;
    struct Node *left;
    struct Node *right;
    struct Node *p;
} Node;

Node *NIL;

void initializeNILNode()
{
    NIL = (Node *)malloc(sizeof(Node));
    NIL->data = 0;
    NIL->isRed = false;
    NIL->left = NIL->right = NIL->p = NIL;
}

void printTree(Node *root, int space)
{
    if (root == NIL)
        return;

    space += 10;

    printTree(root->right, space);

    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    if (root->isRed)
        printf("[%d]\n", root->data);
    else
        printf("%d\n", root->data);

    printTree(root->left, space);
}

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NIL;
    newNode->p = NIL;
    newNode->isRed = true;
    return newNode;
}

void leftRotate(Node **root, Node *x)
{
    Node *y = x->right;
    x->right = y->left;
    if (y->left != NIL)
        y->left->p = x;
    y->p = x->p;
    if (x->p == NIL)
        (*root) = y;
    else if (x == x->p->left)
        x->p->left = y;
    else
        x->p->right = y;
    y->left = x;
    x->p = y;
}

void rightRotate(Node **root, Node *x)
{
    Node *y = x->left;
    x->left = y->right;
    if (y->right != NIL)
        y->right->p = x;
    y->p = x->p;
    if (x->p == NIL)
        (*root) = y;
    else if (x == x->p->right)
        x->p->right = y;
    else
        x->p->left = y;
    y->right = x;
    x->p = y;
}

void insertFixup(Node **root, Node *z)
{
    while (z->p->isRed == true)
    {
        if (z->p == z->p->p->left)
        {
            Node *y = z->p->p->right;
            if (y->isRed == true)
            {
                z->p->isRed = false;
                y->isRed = false;
                z->p->p->isRed = true;
                z = z->p->p;
            }
            else
            {
                if (z == z->p->right)
                {
                    z = z->p;
                    leftRotate(root, z);
                }
                z->p->isRed = false;
                z->p->p->isRed = true;
                rightRotate(root, z->p->p);
            }
        }
        else
        {
            Node *y = z->p->p->left;
            if (y->isRed == true)
            {
                z->p->isRed = false;
                y->isRed = false;
                z->p->p->isRed = true;
                z = z->p->p;
            }
            else
            {
                if (z == z->p->left)
                {
                    z = z->p;
                    rightRotate(root, z);
                }
                z->p->isRed = false;
                z->p->p->isRed = true;
                leftRotate(root, z->p->p);
            }
        }
    }
    (*root)->isRed = false;
}

void insert(Node **root, int data)
{
    Node *x = *root;
    Node *y = NIL;

    Node *z = createNode(data);

    while (x != NIL)
    {
        y = x;
        if (z->data < x->data)
            x = x->left;
        else
            x = x->right;
    }

    z->p = y;

    if (y == NIL)
        *root = z;
    else if (z->data < y->data)
        y->left = z;
    else
        y->right = z;

    insertFixup(root, z);
}

Node *search(Node *p, int key)
{
    if (p == NIL || key == p->data)
        return p;
    if (key < p->data)
        return search(p->left, key);
    else
        return search(p->right, key);
}

Node *minimum(Node *root)
{
    Node *p = root;
    while (p->left != NIL)
        p = p->left;
    return p;
}

Node *maximum(Node *root)
{
    Node *p = root;
    while (p->right != NIL)
        p = p->right;
    return p;
}

void transplant(Node **root, Node *u, Node *v)
{
    if (u->p == NIL)
        (*root) = v;
    else if (u == u->p->left)
        u->p->left = v;
    else
        u->p->right = v;

    if (v != NIL)
        v->p = u->p;
}

void deleteFixup(Node **root, Node *x)
{
    while (x != *root && x->isRed == false)
    {
        if (x == x->p->left)
        {                          // x is a left child
            Node *w = x->p->right; // w is x's sibling

            if (w->isRed)
            { // case 1
                w->isRed = false;
                x->p->isRed = true;
                leftRotate(root, x->p);
                w = x->p->right;
            }

            if (!w->left->isRed && !w->right->isRed)
            { // case 2
                w->isRed = true;
                x = x->p;
            }
            else
            {
                if (!w->right->isRed)
                { // case 3
                    w->left->isRed = false;
                    w->isRed = true;
                    rightRotate(root, w);
                    w = x->p->right;
                }

                // case 4
                w->isRed = x->p->isRed;
                x->p->isRed = false;
                w->right->isRed = false;
                leftRotate(root, x->p);
                x = *root;
            }
        }
        else
        { // same as above, but with 'right' and 'left' interchanged
            Node *w = x->p->left;

            if (w->isRed)
            {
                w->isRed = false;
                x->p->isRed = true;
                rightRotate(root, x->p);
                w = x->p->left;
            }

            if (!w->right->isRed && !w->left->isRed)
            {
                w->isRed = true;
                x = x->p;
            }
            else
            {
                if (!w->left->isRed)
                {
                    w->right->isRed = false;
                    w->isRed = true;
                    leftRotate(root, w);
                    w = x->p->left;
                }

                w->isRed = x->p->isRed;
                x->p->isRed = false;
                w->left->isRed = false;
                rightRotate(root, x->p);
                x = *root;
            }
        }
    }

    x->isRed = false;
}

void delete(Node **root, int data)
{
    Node *z = search((*root), data);
    Node *y = z;
    bool yOriginalColor = y->isRed;
    Node *x;

    if (z->left == NIL)
    {
        x = z->right;
        transplant(root, z, z->right);
    }
    else if (z->right == NIL)
    {
        x = z->left;
        transplant(root, z, z->left);
    }
    else
    {
        y = minimum(z->right);
        yOriginalColor = y->isRed;
        x = y->right;

        if (y->p != z)
        {
            transplant(root, y, y->right);
            y->right = z->right;
            y->right->p = y;
        }
        else
        {
            x->p = y;
        }

        transplant(root, z, y);
        y->left = z->left;
        y->left->p = y;
        y->isRed = z->isRed;
    }

    if (!yOriginalColor)
    {
        deleteFixup(root, x);
    }

    free(z);
}

int main()
{
    int arr[] = {8, 3, 10, 1, 4, 9, 11, 6, 5, 7, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    initializeNILNode();
    Node *root = NIL;

    for (int i = 0; i < n; ++i)
        insert(&root, arr[i]);

    printTree(root, 0);

    delete (&root, 8);

    printf("----------------\n");
    printTree(root, 0);

    return 0;
}
