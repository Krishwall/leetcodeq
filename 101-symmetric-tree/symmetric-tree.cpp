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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return utilSymmetric(root->left,root->right);

    }

    bool utilSymmetric(TreeNode*& leftTree,TreeNode*& rightTree)
    {   
        if(!leftTree || !rightTree)
        
        return (leftTree==rightTree);

        return (leftTree->val==rightTree->val && utilSymmetric(leftTree->left,rightTree->right) && utilSymmetric(leftTree->right,rightTree->left));
    }
};