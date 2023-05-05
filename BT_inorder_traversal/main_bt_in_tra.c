/***********************************************************************/
/**
    LeetCode 
    Purpose: #94, binary tree inorder traversal
    @author: Frank Nguen
    @date: 0x-05-2023
*/
#if 1
#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for a binary tree node.
 *
*/
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int* inorderTraversal(struct TreeNode* root, int* returnSize);
//void inorderTraversal(struct TreeNode* root);
void printTree(struct TreeNode* root, int level);
struct TreeNode* createNode(int value);
void insertNode(struct TreeNode* root, int value);

/***********************************************************************/
/**
 * main: -
 *
 * 
 */
int main(){

    struct TreeNode* root = createNode(2);

    insertNode(root, 1);
    insertNode(root, 3);
    // insertNode(root, 3);
    // insertNode(root, 5);
    // insertNode(root, 6);
    // insertNode(root, 7);
    // insertNode(root, 8);
    // insertNode(root, 9);
    // insertNode(root, 10);
    // insertNode(root, 11);
    // insertNode(root, 12);
    // insertNode(root, 13);
    printf("\n ---------------------------- \n");
    printTree(root, 0);
    printf("\n ---------------------------- \n");
    //inorderTraversal(root);

    int* result;
    int returnSize;
    result = inorderTraversal(root, &returnSize);

    for(int i=0; i<returnSize; i++){
        printf("\n %d", result[i]);
    }

    printf("\n ---------------------------- \n");
    printf("\n PASS-TEST \n");
    return 0;
}

/***********************************************************************/
/**
 * printTree: -
 * @value
 *  
 * return:
 *
 * create a new node by allocating memory for a TreeNode object 
 * and initializing its members. For example:
 */
void printTree(struct TreeNode* root, int level) {
    if (root != NULL) {
        printTree(root->right, level+1);
        for (int i = 0; i < level; i++) {
            printf("    ");
        }
        printf("%d\n", root->val);
        printTree(root->left, level+1);
    }
}

/**
 * createNode: -
 * @value
 *  
 * return:
 *
 * create a new node by allocating memory for a TreeNode object 
 * and initializing its members. For example:
 */
struct TreeNode* createNode(int value) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/**
 * insertNode: -
 * @value
 *  
 * return:
 *
 * create a new node by allocating memory for a TreeNode object 
 * and initializing its members. For example:
 */
void insertNode(struct TreeNode* root, int value) {
    if (root == NULL) {
        root = createNode(value);
        return;
    }
    if (value < root->val) {
        if (root->left == NULL) {
            root->left = createNode(value);
        } else {
            insertNode(root->left, value);
        }
    } else {
        if (root->right == NULL) {
            root->right = createNode(value);
        } else {
            insertNode(root->right, value);
        }
    }
}

/**
 * searchNode: -
 * @value
 *  
 * return:
 *
 * create a new node by allocating memory for a TreeNode object 
 * and initializing its members. For example:
 */
struct TreeNode* searchNode(struct TreeNode* root, int value) {
    if (root == NULL || root->val == value) {
        return root;
    }
    if (value < root->val) {
        return searchNode(root->left, value);
    } else {
        return searchNode(root->right, value);
    }
}
#endif
/**
 * inorderTraversal: -
 * @value
 *  
 * return:
 *
 * There are several ways to traverse a binary tree, including in-order, 
 * pre-order, and post-order traversal. Here's an example of in-order 
 * traversal, which visits the left subtree, then the current node, 
 * then the right subtree:
 */
// void inorderTraversal(struct TreeNode* root) {
//     if (root != NULL) {
//         inorderTraversal(root->left);
//         printf("%d ", root->val);
//         inorderTraversal(root->right);
//     }
// }

#if 1
void inorderTraversalHelper(struct TreeNode* root, int* result, int* idx) {
    if (root == NULL) {
        return;
    }
    inorderTraversalHelper(root->left, result, idx);
    result[*idx] = root->val;
    (*idx)++;
    inorderTraversalHelper(root->right, result, idx);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = malloc(sizeof(int) * 1000); // assuming the tree has at most 1000 nodes
    *returnSize = 0;
    inorderTraversalHelper(root, result, returnSize);
    return result;
}
#endif
/***********************************************************************/