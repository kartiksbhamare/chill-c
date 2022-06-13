#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
} Node;

Node *createNode(int val)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = val;
    n->right = NULL;
    n->left = NULL;
    return n;
}

Node *searchBST(Node *root, int key)
{
    if (root == NULL || root->data == key)
        return root;

    if (root->data < key)
        return searchBST(root->right, key);

    return searchBST(root->left, key);
}

Node *insertNodeBST(Node *node, int key)
{
    if (node == NULL)
        return createNode(key);

    if (key < node->data)
        node->left = insertNodeBST(node->left, key);
    else if (key > node->data)
        node->right = insertNodeBST(node->right, key);

    return node;
}

Node *minValueNode(Node *node)
{
    Node *current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

Node *deleteNodeBST(Node *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNodeBST(root->left, key);

    else if (key > root->data)
        root->right = deleteNodeBST(root->right, key);

    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        Node *temp = minValueNode(root->right);

        root->data = temp->data;

        root->right = deleteNodeBST(root->right, temp->data);
    }
    return root;
}

void inorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void postorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

void preorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int findMinElement(Node *node)
{
    Node *current = node;

    while (current->left != NULL)
    {
        current = current->left;
    }
    return (current->data);
}

int findMaxElement(Node *node)
{
    Node *current = node;
    while (current->right != NULL)
        current = current->right;

    return (current->data);
}

void userChoice()
{
    printf("\nUSER CHOICE!\n");
    printf("1. Search BST\n");
    printf("2. Insert Node BST\n");
    printf("3. Delete Node BST\n");
    printf("    4. InOrder Traversal\n");
    printf("    5. PreOrder Traversal\n");
    printf("    6. PostOrder Traversal\n");
    printf("7. Find Minimum Element\n");
    printf("8. Find Maximum Element\n");
    printf("0. Exit Program\n");
}

int main()
{
    Node *root = NULL;

again:

    userChoice();
    int inp;
    int se;

    int exitFlag = 0;
    printf("Enter choice: ");
    scanf("%d", &inp);
    printf("\n");
    switch (inp)
    {
    case 0:
    {
        exitFlag = 1;
        break;
    }

    case 1:
    {
        //Search BST
        printf("Enter the element to be Searched :");
        scanf("%d", &se);
        if (searchBST(root, se))
        {
            printf("%d Found at address %p\n", se, root);
        }
        else
        {
            printf("Element Not Found!");
        }

        break;
    }

    case 2:
    {
        //Insert Node BST
        printf("Enter the element to be inserted :");
        scanf("%d", &se);
        root = insertNodeBST(root, se);
        printf("%d INSERTED\n", se);

        break;
    }
    case 3:
    {
        //Delete Node
        printf("Enter the element to be deleted :");
        scanf("%d", &se);
        if (searchBST(root, se))
        {
            printf("%d Found at address %p\n", se, root);
            root = deleteNodeBST(root, se);
            printf("%d DELETED\n", se);
        }
        else
        {
            printf("Element Not Found!\n");
        }

        break;
    }
    case 4:
    {
        //Inorder Traversal
        printf("Inorder Traversal\n");
        inorderTraversal(root);
        break;
    }

    case 5:
    {
        //Preorder Traversal
        printf("PreOrder Traversal\n");
        preorderTraversal(root);
        break;
    }

    case 6:
    {
        //PostOrder Traversal
        printf("PostOrder Traversal\n");
        postorderTraversal(root);
        break;
    }

    case 7:
    {
        //Find Minimum Element
        printf("Minimum Element: ");
        if (root)
        {
            printf("%d\n", findMinElement(root));
        }
        else
        {
            printf("Tree Empty");
        }
        break;
    }

    case 8:
    {
        //Find Maximum Element
        printf("Maximum Element: ");
        if (root)
        {
            printf("%d\n", findMaxElement(root));
        }
        else
        {
            printf("Tree Empty");
        }

        break;
    }

    default:
        printf("WRONG CHOICE! TRY AGAIN!\n");
    }
    
    printf("\n\n");
    if (exitFlag == 0)
    {
        printf("\n\nTREE\n");
        inorderTraversal(root);
        printf("\n\n");
        goto again;
    }
    return 0;
}