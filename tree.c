/* Implementing a binary search tree in C */

#include <stdio.h>
#include <stdlib.h>

/* Structure of a node in BST */ 
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    /* TODO: Create a new node. */
    Node* newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value) {
    /* TODO: Insert the given value in the BST - call createNode() as a helper function.
             The BST property must not be violated. *
           */

    if (root == NULL) {
        Node* newNode = createNode(value);
        root = newNode;
    } else {
        // traverse
        if (value < root->data) {
            
            insert(root->left,value);
        }
        if (value > root->data) {
            insert(root->right,value);
        }
    }
    return root;
    
}


Node* search(Node* root, int value) {
    /* TODO: Search the tree for the given value. You must use the BST property. */

}

void inOrderTraversal(Node* root) {
    /* TODO: Traverse the tree in order to print values in ascending order. */
    if (root->left) {
        inOrderTraversal(root->left);
    }
    if (root->data) {
        printf("%d",root->data);
    }
    if (root->right) {
        inOrderTraversal(root->right);
    }
}

void freeTree(Node* root) {
    /* TODO: Free any allocated memory */

}

int main() { 
    int n;
    printf("Enter the number of values to be inserted: ");
    scanf("%d", &n);

    int values[n];
    printf("Enter %d integers in random order: ", n);
    for(int i=0; i< n; i++) {
        scanf("%d", values+i);
    }

    Node* root = NULL;
    /* Insert values into BST */ 
    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    /* Print values in a sorted manner using in-order traversal */
    printf("In-order traversal: ");
    inOrderTraversal(root);
    printf("\n");

    /* Search for a value in BST */
    int searchValue;
    printf("Enter a value to be searched: ");
    scanf("%d", &searchValue);
    if (search(root, searchValue)) {
        printf("%d found in BST.\n", searchValue);
    } else {
        printf("%d not found in BST.\n", searchValue);
    }

    freeTree(root); /* free the tree */

    return 0;
}
