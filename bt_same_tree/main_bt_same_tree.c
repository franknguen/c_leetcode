/***********************************************************************/
/**
    LeetCode 
    Purpose: #100, same tree
    @author: Frank Nguen
    @date:   0x-05-2023
*/
/***********************************************************************/
#if 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Definition for a binary tree node.
 *
*/
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Funs with TreeNode data structure.
 *
*/
struct TreeNode* createNode(int value);
void insertNode(struct TreeNode* root, int value);

void printTree(struct TreeNode* root, int level);

int* inorderTraversal(struct TreeNode* root, int* returnSize);
//void inorderTraversal(struct TreeNode* root);
void inorderTraversalHelper(struct TreeNode* root, int* result, int* idx);
bool isSameTree(struct TreeNode* p, struct TreeNode* q);

/***********************************************************************/
/**
 * main: -
 *
 * return: 0
 *
 * to test case
 */
int main(){
    printf("\n ---------------------------- \n");
    struct TreeNode* root1 = createNode(1);
    root1->left  = createNode(2);
    root1->right = createNode(3);
    printTree(root1, 0);
    printf("\n ---------------------------- \n");
    struct TreeNode* root2 = createNode(1);
    root2->left  = createNode(2);
    root2->right = createNode(3);
    printTree(root2, 0);
    printf("\n ---------------------------- \n");

    int* result1, result2;
    int returnSize1, returnSize2;
    
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
 * to print tree 
 * 
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
 * createNode: - (or newNode)
 * @value
 *  
 * return:
 *
 * to create or new node
 * 
 */
struct TreeNode* createNode(int value) {
    struct TreeNode* node 
        = (struct TreeNode*)malloc(sizeof(struct TreeNode));

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
 * to insert node ... 
 * 
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

#endif

#if 1
/**
 * isSameTree: -
 * @value
 *  
 * return:
 *
 * to 
 * 
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    // Base case: Both nodes are NULL
    if (p == NULL && q == NULL) {
        return true;
    }

    // If one node is NULL and the other is not, or their values are different
    if (p == NULL || q == NULL || p->val != q->val) {
        return false;
    }

    // Recursively check the left and right subtrees
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
#endif
/***********************************************************************/
