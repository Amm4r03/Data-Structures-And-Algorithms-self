// create a binary tree
// inserts nodes into the tree
// prints tree using inorder method
// searches for key in tree recursively

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* root;

// creates a tree node
struct TreeNode* createTreeNode(int value)
{
    struct TreeNode* newNode = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// inserts the node in the tree
struct TreeNode* insertNode(struct TreeNode* root, int value)
{
    if (root==NULL)
    {
        root = createTreeNode(value);
        return root;
    }
    else
    {
        if(value < root->data)
        {
            root->left = insertNode(root->left, value);
        }
        else
        {
            root->right = insertNode(root->right, value);
        }
    }
    return root;
}

void printInorder(struct TreeNode* root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        printInorder(root->left);
        printf("%d ", root->data);
        printInorder(root->right);
    }
    return;
}

void printPreorder(struct TreeNode* root)
{
    if (root == NULL)
    return;
    else
    {
        printf("%d ", root->data);
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

void printPostorder(struct TreeNode* root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        printPostorder(root->left);
        printPostorder(root->right);
        printf("%d ", root->data);
    }
}

bool search(struct TreeNode* root ,int value)
{
    if (root == NULL) return false;
    else if (root->data == value)
    return true;
    else if (value <= root->data)
    {
        return search(root->left, value);
    }
    else return search(root->right, value);
}

int main()
{
    root = NULL;

    int entries;
    printf("enter the number of nodes to be inserted in the tree : ");
    scanf("%d", &entries);

    for(int i = 0; i < entries; i++)
    {
        int value;
        printf("node %d : ", i+1);
        scanf("%d", &value);
        if (i == 0)
        {
            root = insertNode(root, value);
        }
        else
        {
            insertNode(root, value);
        }
    }

    printf("enter number to be searched in tree : ");
    int key;
    scanf("%d", &key);

    if (search(root, key) == true)
    {
        printf("found %d\n", key);
    }
    else printf("not found\n");

    printf("inorder traversal :\t");
    printInorder(root);

    printf("\npreorder traversal :\t");
    printPreorder(root);

    printf("\npostorder traversal :\t");
    printPostorder(root);

    return 0;
}