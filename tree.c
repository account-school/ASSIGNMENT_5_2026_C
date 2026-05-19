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
    Node* originalNode = root;
    if (root) {
        while (root->left || root->right) {
            if (value < root->data) {
                if (root->left) {
                    root = root->left;
                } else {
                    break; // if theres no longer a thing to search, your finished
                }
            } else if (value > root->data) {
                if (root->right) {
                    root = root->right;
                } else {
                    break; // if theres no longer a thing to search, your finished
                }
            } else {
                    root = originalNode;
                     return root; // value already exists, exit early.
            }
        }
    }
    if (root) {
        if (value < root->data) {
            root->left = createNode(value);
        } else if (value > root->data) {
            root->right = createNode(value);
        }
    }
    if (originalNode != NULL) {
        return originalNode;
    }
    if (!root) {
        return createNode(value);
    }
    return root;
}

void printNode(Node* node) {
    printf("[");
    if (node->left) {
        printf("%d <-- ",node->left->data);
    } else {
        printf("XX <-- ");
    }
    if (node) {
        printf("%d",node->data);
    }
    if (node->right) {
        printf(" --> %d",node->right->data);
    } else {
        printf(" --> XX");
    }
    printf("]");
}


Node* search(Node* root, int value) {
    /* TODO: Search the tree for the given value. You must use the BST property. */
    Node* temp = root;
    if (root) {
        while (temp->left || temp->right) {
            //printNode(temp);
            //printf("Value: %d", value);
            //printf("? %d\n", temp->data);
            if (value > temp->data) {
                if (temp->right) {
                    temp = temp->right;
                } else {
                    return NULL;
                }
            } else if (value < temp->data) {
                if (temp->left) {
                    temp = temp->left;
                } else {
                    return NULL;
                }                
            } else { // if equal
                return temp;
            }
        }
        if (temp->data == value) {
            return temp;
        }
        return NULL;
    }


}

void inOrderTraversal(Node* root) {
    /* TODO: Traverse the tree in order to print values in ascending order. */
    if (root->left) {
        inOrderTraversal(root->left);
    }
    if (root) {
        printf("%d ", root->data);
    }
    if (root->right) {
        inOrderTraversal(root->right);
    }
}

void freeTree(Node* root) {
    /* TODO: Free any allocated memory */
    if (root->left) {
        freeTree(root->left);
    }
    if (root->right) {
        freeTree(root->right);
    }
    if (root) {
        free(root);
    }
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
        //printNode(root);
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
