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
    int goodNodes(TreeNode* root) {
        int max_val=root->val;
        int cnt=0;
        countGood(root,max_val,cnt);
        return cnt;
    }
    void countGood(TreeNode* root,int max_val, int& cnt)
    {   
        if(!root) return ;
        if(root->val>=max_val)
        {
            cnt++;max_val=root->val;
        }
        countGood(root->left,max_val,cnt);
        countGood(root->right,max_val,cnt);
    }
};