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
    
    unordered_map<int,int> post_val_idx;
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n=preorder.size();
        for(int i=0;i<n;i++)
        {
            post_val_idx[postorder[i]]=i;
        }
        return build(0,n-1,0,n-1,preorder,postorder);
    }
    TreeNode* build(int i1,int i2,int j1,int j2,vector<int>& preorder, vector<int>& postorder)
    {
        if (i1>i2 && j1>j2)
        {
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[i1]);
        if(i1!=i2)
        {
            int left_val=preorder[i1+1];
            int mid=post_val_idx[left_val];

            int left_size= mid-j1+1;
            root->left=build(i1+1,i1+left_size,j1,mid,preorder,postorder);
            root->right=build(i1+left_size+1,i2,mid+1,j2-1,preorder,postorder);


        }
        return root;
    }
};