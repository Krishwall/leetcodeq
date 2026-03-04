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
    bool checkSame(TreeNode*p, TreeNode*q)
    {
        if(!p && !q) return true;
        if(!p || !q) return false;
        if(p->val !=q->val) return false;

        return checkSame(p->left,q->left) && checkSame(p->right,q->right);
    }
    bool helper(TreeNode* p,TreeNode*q)
    {
        if(!p) return false;
        if(checkSame(p,q)) return true;
        return helper(p->left,q)|| helper(p->right,q);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return helper(root,subRoot);
    }

};