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

        vector<int> inorder=preorder;
        sort(inorder.begin(),inorder.end());
        unordered_map<int,int> inMap;
        for(int i=0;i<n;++i)
        {
            inMap[inorder[i]]=i;
        }
        return constructBST(preorder,0,n-1,inorder,0,n-1,inMap);

    }
    TreeNode* constructBST(vector<int> &preorder,int pres,int pree,vector<int> inorder,int inStart,int inend,unordered_map<int,int> inMap)

    {
        
        if(pres>pree || inStart>inend) return NULL;
        TreeNode* root=new TreeNode(preorder[pres]);
        int inRoot=inMap[preorder[pres]];
        int leftRoot=inRoot-inStart;
        root->left=constructBST(preorder,pres+1,pres+leftRoot,inorder,inStart,inRoot-1,inMap);
        root->right=constructBST(preorder,pres+leftRoot+1,pree,inorder,inRoot+1,inend,inMap);
        return root;
    }
};