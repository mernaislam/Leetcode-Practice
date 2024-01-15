/// @author Merna Islam
/// @date 09/01/2024.
/// @link https://leetcode.com/problems/leaf-similar-trees

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
    void fillVector(TreeNode* node, vector<int>& leaves){
        if(node == nullptr){
            return;
        }
        if(node->left == nullptr && node->right == nullptr){
            leaves.push_back(node->val);
            return;
        }
        fillVector(node->left, leaves);
        fillVector(node->right, leaves);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1;
        vector<int> leaves2;

        fillVector(root1, leaves1);
        fillVector(root2, leaves2);

        return leaves1 == leaves2;
    }
};