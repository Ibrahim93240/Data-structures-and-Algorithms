#include <stdio.h>
#include <stdlib.h>

// Define a structure for the nodes of the binary search tree
struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the BST
struct TreeNode* insertNode(struct TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else {
        if (data <= root->data) {
            root->left = insertNode(root->left, data);
        } else {
            root->right = insertNode(root->right, data);
        }
        return root;
    }
}

// Function to perform inorder traversal of the BST (descending order)
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->right); // Traverse right subtree
        printf("%d ", root->data); // Print root
        inorderTraversal(root->left); // Traverse left subtree
    }
}

int main() {
    struct TreeNode* root = NULL;
    
    // Insert elements into the BST
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);
    
    // Print elements in descending order using inorder traversal
    printf("Elements in descending order (BST):\n");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
