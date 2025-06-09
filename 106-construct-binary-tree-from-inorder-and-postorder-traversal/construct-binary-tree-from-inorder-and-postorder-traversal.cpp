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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> inMap;
       
        int n=inorder.size();
        for(int i=0;i<n;++i)
        {
            inMap[inorder[i]]=i;
        }
        int poEnd=n-1;
        return binaryTree(postorder,poEnd,inorder,0,n-1,inMap);
    }

    TreeNode* binaryTree(vector<int>& postOrder,int& poEnd, vector<int>& inorder, int inStart,int inEnd,unordered_map<int,int>& inMap)
    {   
        if( inStart>inEnd) return NULL;
        TreeNode* root=new TreeNode(postOrder[poEnd]);

        int inRoot=inMap[postOrder[poEnd]];
        poEnd--;
        
        root->right=binaryTree(postOrder,poEnd,inorder,inRoot+1,inEnd,inMap);
        root->left=binaryTree(postOrder,poEnd,inorder,inStart,inRoot-1,inMap);

        return root;
    }
};