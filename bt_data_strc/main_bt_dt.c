/***********************************************************************/
/**
    LeetCode 
    Purpose: #94, binary tree inorder traversal
    @author: Frank Nguen
    @date:   0x-05-2023
    https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/
*/
/***********************************************************************/
#if 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

/**
 * Definition for a binary tree node.
 *
*/
struct TreeNode {
    //
    int val;
    
    //
    struct TreeNode *left;
    
    //
    struct TreeNode *right;
};

/**
 * Funs with TreeNode data structure.
 *
*/

//
struct TreeNode* createNode(int value);

//
void insertNode(struct TreeNode* root, int value);

//
void printTree(struct TreeNode* root, int level);

//
int* inorderTraversal(struct TreeNode* root, int* returnSize);

//
void inorderTraversal_1(struct TreeNode* root);

//
bool isSameTree(struct TreeNode* p, struct TreeNode* q);

//
bool isSymmetric(struct TreeNode* root);

//
int maxDepth(struct TreeNode* root);

//
struct TreeNode* sortedArrayToBST(int* nums, int numsSize);

//
bool isBalanced(struct TreeNode* root);

//
int minDepth(struct TreeNode* root);

/***********************************************************************/
/**
 * main: -
 *
 * return: 0
 *
 * to test case
 */
int main(){
    //
    struct TreeNode* root = createNode(2);

    //
    insertNode(root, 1);
    insertNode(root, 3);
    insertNode(root, 3);
    insertNode(root, 5);
    insertNode(root, 6);
    insertNode(root, 7);
    insertNode(root, 8);
    insertNode(root, 9);
    insertNode(root, 10);
    insertNode(root, 11);
    insertNode(root, 12);
    insertNode(root, 13);
    printf("\n ---------------------------- \n");
    
    //
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

    struct TreeNode* root2 = createNode(1);
    root2->right       = createNode(2);
    root2->right->left = createNode(3);

    printTree(root2, 0);
    
    printf("\n ---------------------------- \n");

    struct TreeNode* root3 = createNode(1);
 
    root3->left = createNode(2);
    root3->right = createNode(3);
    root3->left->left = createNode(4);
    root3->left->right = createNode(5);
 
    printf("Height of tree is %d", maxDepth(root3));

    // printf("\n Max depth of tree 1 = %d", maxDepth(root));
    // printf("\n Max depth of tree 2 = %d", maxDepth(root2));
    printf("\n ---------------------------- \n");

    int nums[] = {-10, -3, 0, 5, 9};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    struct TreeNode* root4 = sortedArrayToBST(nums, numsSize);
    
    printf("Inorder traversal of the constructed BST: ");
    inorderTraversal_1(root4);
    printf("\n");
    printTree(root4,0);
    printf("\n");

    printf("\n Tree is balanced or not: %d",isBalanced(root4));

    printf("\n Mindepth of Root: %d",minDepth(root4));

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
    //
    if (root != NULL) {
        //
        printTree(root->right, level+1);
        
        //
        for (int i = 0; i < level; i++) {
            printf("    ");
        }

        //
        printf("%d\n", root->val);
        
        //
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
    
    //
    struct TreeNode* node 
        = (struct TreeNode*)malloc(sizeof(struct TreeNode));

    //
    node->val = value;

    //
    node->left = NULL;
    
    //
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
    //
    if (root == NULL) {
        //
        root = createNode(value);
        return;
    }

    //
    if (value < root->val) {
        //
        if (root->left == NULL) {
            //
            root->left = createNode(value);
        } else {
            //
            insertNode(root->left, value);
        }
    } else {
        //
        if (root->right == NULL) {
            //
            root->right = createNode(value);
        } else {
            //
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
 * to search ... 
 * 
 */
struct TreeNode* searchNode(struct TreeNode* root, int value) {
    //
    if (root == NULL || root->val == value) {
        return root;
    }

    //
    if (value < root->val) {
        //
        return searchNode(root->left, value);
    } else {
        //
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
void inorderTraversal_1(struct TreeNode* root) {
    //
    if (root != NULL) {
        //
        inorderTraversal_1(root->left);
        
        //
        printf("%d ", root->val);
        
        //
        inorderTraversal_1(root->right);
    }
}

/**
 * inorderTraversalHelper: -
 * @value
 *  
 * return:
 *
 * to help save value on recursive ... 
 * 
 */
void inorderTraversalHelper(struct TreeNode* root, int* result, int* idx) {
    //
    if (root == NULL) {
        return;
    }

    //
    inorderTraversalHelper(root->left, result, idx);
    
    //
    result[*idx] = root->val;
    
    //
    (*idx)++;
    
    //
    inorderTraversalHelper(root->right, result, idx);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    //
    int* result = malloc(sizeof(int) * 1000); // assuming the tree has at most 1000 nodes
    
    //
    *returnSize = 0;
    
    //
    inorderTraversalHelper(root, result, returnSize);
    
    return result;
}

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
/***********************************************************************/

/**
 * isSymmetric: -
 * @value
 *  
 * return:
 *
 * to 
 * 
 */
bool isSymmetricHelper(struct TreeNode* left, struct TreeNode* right) {
    // Base case: Both nodes are NULL
    if (left == NULL && right == NULL) {
        return true;
    }

    // If one node is NULL and the other is not, or their values are different
    if (left == NULL || right == NULL || left->val != right->val) {
        return false;
    }

    // Recursively check the corresponding nodes on the left and right subtrees
    return isSymmetricHelper(left->left, right->right) && isSymmetricHelper(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }

    // Pass the left and right subtrees of the root to the helper function
    return isSymmetricHelper(root->left, root->right);
}

/**
 * maxDepth: -
 * @value
 *  
 * return:
 *
 * to 
 * 
 */
int maxDepth(struct TreeNode* root){
    //
    if(root == NULL){
        return 0;
    } else {
        //
        int left_depth  = maxDepth(root->left);
        
        //
        int right_depth = maxDepth(root->right);

        //
        if(left_depth > right_depth){
            //
            return left_depth + 1;
        } else {
            //
            return right_depth + 1;
        }
    }
}

/**
 * sortedArrayToBSTHelper: -
 * @value
 *  
 * return:
 *
 * to 
 * 
 */
struct TreeNode* sortedArrayToBSTHelper(int* nums, int start, int end) {
    //
    if (start > end) {
        return NULL;
    }
    
    //
    int mid = start + (end - start) / 2;
    
    //
    struct TreeNode* root = createNode(nums[mid]);

    //
    root->left = sortedArrayToBSTHelper(nums, start, mid - 1);
    
    //
    root->right = sortedArrayToBSTHelper(nums, mid + 1, end);

    return root;
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    //
    if (nums == NULL || numsSize == 0) {
        return NULL;
    }
    //
    return sortedArrayToBSTHelper(nums, 0, numsSize - 1);
}

/**
 * isBalanced: -
 * @value
 *  
 * return:
 *
 * to 
 * 
 */
bool isBalanced(struct TreeNode* root){
    //
    if(root == NULL){
        return true;
    } else {
        //
        int left_depth  = maxDepth(root->left);
        
        //
        int right_depth = maxDepth(root->right);

        //
        int k = (left_depth > right_depth) ? (left_depth - right_depth) : (right_depth - left_depth);

        //
        if ( (k < 2) && (isBalanced(root->left)) && (isBalanced(root->right)) ){
            return true;
        } else {
            return false;
        }
    }
}

/**
 * minDepth: -
 * @value
 *  
 * return:
 *
 * to 
 * 
 */
int minDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    // If the current node is a leaf node, return 1
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }

    int leftDepth  = INT_MAX;
    int rightDepth = INT_MAX;

    // Calculate the minimum depth of the left subtree
    if (root->left != NULL) {
        leftDepth = minDepth(root->left);
    }

    // Calculate the minimum depth of the right subtree
    if (root->right != NULL) {
        rightDepth = minDepth(root->right);
    }

    // Return the minimum depth among the left and right subtrees, plus 1 for the current node
    return (leftDepth < rightDepth) ? (leftDepth + 1) : (rightDepth + 1);
}

/**
 * hasPathSum: -
 * @value
 *  
 * return:
 *
 * to 
 * 
 */
bool hasPathSum(struct TreeNode* root, int targetSum){
    // 
    if(root == NULL)
        return false;
    
    // if only have root value
    if(root->left == NULL && root->right == NULL && targetSum == root->val)
        return true;
    else
    // 
        return ( (hasPathSum(root->right, targetSum - root->val)) || (hasPathSum(root->left, targetSum - root->val)));

}
