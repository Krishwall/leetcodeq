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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root;
        map<int,int> inMap;
        int n=inorder.size();
        for(int i=0;i<n;++i){
            inMap[inorder[i]]=i;
        }
        int preStart=0;
        root=buildTree(inorder,0,n-1,preorder,preStart,inMap);
        return root;
    }
    TreeNode*  buildTree(vector<int>& inorder,int inStart,int inEnd,vector<int>& preorder, int& preStart,map<int,int>& inMap){
        
        if(preStart==preorder.size()|| inStart>inEnd)  return NULL;
        TreeNode* root=new TreeNode(preorder[preStart]);

        int inRoot=inMap[root->val];
        preStart++;

        root->left=buildTree(inorder,inStart,inRoot-1,preorder,preStart,inMap);
        root->right=buildTree(inorder,inRoot+1,inEnd,preorder,preStart,inMap);

        return root;;
    }
};