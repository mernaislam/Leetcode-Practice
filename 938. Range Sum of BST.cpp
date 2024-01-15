/// @author Merna Islam
/// @date 08/01/2024.
/// @link https://leetcode.com/problems/range-sum-of-bst

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int lowVal, highVal;
    int solve(TreeNode* node){
        if(node == nullptr){
            return 0;
        }
        if(node->val <= highVal && node->val >= lowVal){
            return node->val + solve(node->left) + solve(node->right);
        }
        else if(node->val < lowVal){
            return solve(node->right);
        }
        else {
            return solve(node->left);
        }
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        this->lowVal = low;
        this->highVal = high;
        return solve(root);
    }
};