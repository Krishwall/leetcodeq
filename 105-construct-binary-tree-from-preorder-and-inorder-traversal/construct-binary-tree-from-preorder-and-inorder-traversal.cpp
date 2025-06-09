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

        root=buildTree(inorder,0,n-1,preorder,0,n-1,inMap);
        return root;
    }
    TreeNode*  buildTree(vector<int>& inorder,int inStart,int inEnd,vector<int>& preorder, int preStart,int preEnd,map<int,int>& inMap){
        
        if(preStart>preEnd || inStart>inEnd)  return NULL;
        TreeNode* root=new TreeNode(preorder[preStart]);

        int inRoot=inMap[root->val];
        int lefttree=inRoot-inStart;

        root->left=buildTree(inorder,inStart,inRoot-1,preorder,preStart+1,preStart+lefttree,inMap);
        root->right=buildTree(inorder,inRoot+1,inEnd,preorder,preStart+lefttree+1,preEnd,inMap);

        return root;;
    }
};