#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int data;
    struct node* left, *right;
}node;

node* newnode (int x)
{
    node * n = malloc (sizeof(node));
    n->data = x;
    n->left = n->right = NULL;
    return n;
}

node* insert (node*root, int x)
{
    if(root == NULL)
    {
        node *n = newnode(x);
        root = n;
    }
    else if(x < root->data)
        {
           root->left = insert(root->left, x);
        }
    else
            root->right = insert(root->right, x);

 return root;
}
node* findmin (node *root)
{
    if (root == NULL)
        return root;
    else if (root ->left == NULL)
        return root;
    else
        return findmin (root->left);
}
void print_inorder(node *root)
{
    if(root)
    {
        print_inorder(root->left);
        printf("%d\t", root->data);
        print_inorder(root->right);
    }
}
void print_preorder(node *root)
{
    if(root)
    {
        printf("%d \t",root->data);
        print_preorder(root->left);
        print_preorder(root->right);
    }
}
void print_postorder(node *root)
{
    if(root)
    {
        print_postorder(root->left);
        print_postorder(root->right);
        printf("%d \t",root->data);
    }
}

node* deleteNode (node *root, int x)
{
    if (root == NULL)
        return root;
    else if(x < root->data)
    root->left = deleteNode (root->left , x);
    else if (x > root->data)
        root->right = deleteNode (root->right, x);
    else{
        if (root->left == NULL && root->right == NULL)
        {   free(root);
            return NULL;
        }
        else if (root->left != NULL && root->right != NULL)
        {
            node *min = findmin(root->right);
            root->data = min->data;
            root->right = deleteNode (root->right, min->data);
        }
        else {

            node* temp = root;
            if (root->left != NULL)
                root = root->left;
            if (root ->right != NULL)
                root = root->right;

            free(temp);
        }
    }
    return root;
}

int main()
{
    node*root = NULL;
    node *min = NULL;
    node *n = NULL;
    root=insert(root,100);
    root=insert(root,20);
    root=insert(root,200);
    root=insert(root,10);
    root=insert(root,30);
    root=insert(root,150);
    root=insert(root,300);
    printf("InOrder Tree Traversal:\n\n");
    print_inorder(root);
    printf("\n\n");
    printf("PreOrder Tree Traversal:\n\n");
    print_preorder(root);
    printf("\n\n");
    printf("PostOrder Tree Traversal:\n\n");
    print_postorder(root);
    printf("\n\n");
    min = findmin(root);
    printf("Min = %d\n\n", min->data);
    root = deleteNode(root, 300);
    printf("Post Order Tree Traversal:\n\n");
    print_postorder(root);
    printf("\n\n");
    return 0;
}
