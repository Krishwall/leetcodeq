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
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int tot=INT_MIN;
         height(root,tot);
         return tot;
        
    }
    int height(TreeNode* root,int& tot)
        {if(!root)
            return 0;
        int leftSum=max(0,height(root->left,tot));
        int rightSum=max(0,height(root->right,tot));
        tot=max(tot,leftSum+rightSum+root->val)*1ll;
        return root->val+max(leftSum,rightSum);}
};