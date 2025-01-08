#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
    int color; // 0 for black, 1 for red
} Node;

// Define the structure for the tree
typedef struct {
    Node* root;
} RedBlackTree;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = newNode->parent = NULL;
    newNode->color = 1; // New node is red
    return newNode;
}

// Function to insert a new node into the tree
void insertNode(RedBlackTree* tree, int data) {
    Node* newNode = createNode(data);
    if (tree->root == NULL) {
        tree->root = newNode;
        newNode->color = 0; // Root node is black
    } else {
        Node* current = tree->root;
        Node* parent = NULL;
        while (current != NULL) {
            parent = current;
            if (newNode->data < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        newNode->parent = parent;
        if (newNode->data < parent->data) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
    }
}

// Function to print the tree
void printTree(Node* node) {
    if (node != NULL) {
        printTree(node->left);
        printf("%d (%s)\n", node->data, node->color == 0 ? "black" : "red");
        printTree(node->right);
    }
}

int main() {
    RedBlackTree tree;
    tree.root = NULL;

    insertNode(&tree, 5);
    insertNode(&tree, 3);
    insertNode(&tree, 7);
    insertNode(&tree, 2);
    insertNode(&tree, 4);
    insertNode(&tree, 6);
    insertNode(&tree, 8);

    printf("Red-Black Tree:\n");
    printTree(tree.root);

    return 0;
}
