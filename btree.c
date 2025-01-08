#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the order of the B-Tree (maximum number of children per node)
#define M 4  // Change M to adjust the order

// Structure for a B-Tree node
typedef struct BTreeNode {
    int keys[M - 1];         // Keys in the node (max M-1 keys)
    struct BTreeNode *child[M]; // Child pointers (max M children)
    int n;                   // Current number of keys
    int leaf;                // Boolean to check if the node is a leaf
} BTreeNode;

// Function to create a new B-Tree node
BTreeNode *createNode(int leaf) {
    BTreeNode *node = (BTreeNode *)malloc(sizeof(BTreeNode));
    node->leaf = leaf;
    node->n = 0;
    for (int i = 0; i < M; i++) {
        node->child[i] = NULL;
    }
    return node;
}

// Function to traverse the B-Tree
void traverse(BTreeNode *root) {
    if (root) {
        for (int i = 0; i < root->n; i++) {
            // Visit left child
            if (!root->leaf) {
                traverse(root->child[i]);
            }
            // Print key
            printf("%d ", root->keys[i]);
        }
        // Visit rightmost child
        if (!root->leaf) {
            traverse(root->child[root->n]);
        }
    }
}

// Function to search for a key in the B-Tree
BTreeNode *search(BTreeNode *root, int key) {
    int i = 0;
    while (i < root->n && key > root->keys[i]) {
        i++;
    }

    // If the key is found in this node
    if (i < root->n && key == root->keys[i]) {
        return root;
    }

    // If the key is not found and the node is a leaf
    if (root->leaf) {
        return NULL;
    }

    // Recur to the appropriate child
    return search(root->child[i], key);
}

// Function to split a full child node
void splitChild(BTreeNode *parent, int i, BTreeNode *child) {
    BTreeNode *newChild = createNode(child->leaf);
    int mid = M / 2;  // Middle index for splitting
    newChild->n = mid - 1;

    // Copy the second half of keys to the new child
    for (int j = 0; j < mid - 1; j++) {
        newChild->keys[j] = child->keys[j + mid];
    }

    // Copy the second half of children to the new child
    if (!child->leaf) {
        for (int j = 0; j < mid; j++) {
            newChild->child[j] = child->child[j + mid];
        }
    }

    // Reduce the number of keys in the old child
    child->n = mid - 1;

    // Shift parent children to make room for the new child
    for (int j = parent->n; j >= i + 1; j--) {
        parent->child[j + 1] = parent->child[j];
    }
    parent->child[i + 1] = newChild;

    // Shift parent keys and add the middle key from the old child
    for (int j = parent->n - 1; j >= i; j--) {
        parent->keys[j + 1] = parent->keys[j];
    }
    parent->keys[i] = child->keys[mid - 1];
    parent->n++;
}

// Function to insert a key into a non-full node
void insertNonFull(BTreeNode *node, int key) {
    int i = node->n - 1;

    if (node->leaf) {
        // Find the position to insert the new key
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->n++;
    } else {
        // Find the child that will have the new key
        while (i >= 0 && key < node->keys[i]) {
            i--;
        }
        i++;

        // If the child is full, split it
        if (node->child[i]->n == M - 1) {
            splitChild(node, i, node->child[i]);

            // After split, the middle key moves up; decide which child to go to
            if (key > node->keys[i]) {
                i++;
            }
        }
        insertNonFull(node->child[i], key);
    }
}

// Function to insert a key into the B-Tree
BTreeNode *insert(BTreeNode *root, int key) {
    if (root->n == M - 1) {
        // If the root is full, create a new root
        BTreeNode *newRoot = createNode(0);
        newRoot->child[0] = root;
        splitChild(newRoot, 0, root);
        insertNonFull(newRoot, key);
        return newRoot;
    } else {
        insertNonFull(root, key);
        return root;
    }
}

// Main function
int main() {
    BTreeNode *root = createNode(1);  // Create an empty B-tree
    int choice, key;

    printf("B-Tree Operations (Order %d)\n", M);
    while (1) {
        printf("\n1. Insert\n2. Traverse\n3. Search\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;

            case 2:
                printf("B-Tree: ");
                traverse(root);
                printf("\n");
                break;

            case 3:
                printf("Enter key to search: ");
                scanf("%d", &key);
                if (search(root, key)) {
                    printf("Key %d found in the B-Tree.\n", key);
                } else {
                    printf("Key %d not found in the B-Tree.\n", key);
                }
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
