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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        if(n==0)
            return NULL;
        int idx=0;
        return constructBST(preorder,idx,INT_MAX);

    }
    TreeNode* constructBST(vector<int>& preorder, int& idx, int ub)

    {
        if(idx>=preorder.size() || preorder[idx]>ub) return NULL;

        TreeNode* root=new TreeNode(preorder[idx++]);
        root->left=constructBST(preorder,idx,root->val);
        root->right=constructBST(preorder,idx,ub);

        return root;
        
        
    }
};