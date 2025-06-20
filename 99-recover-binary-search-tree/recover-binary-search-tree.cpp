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
    TreeNode* prev;
    TreeNode* first;
    TreeNode* mid;
    TreeNode* last;
    void recoverTree(TreeNode* root) {

        swapVal(root);

        if(first && last) swap(first->val,last->val);
        else if(first && mid) swap(first->val,mid->val);
    }


    void swapVal(TreeNode* root){

        if(!root) return ;
        swapVal(root->left);

        if(prev!=NULL && prev->val>root->val)
        {   if(first==NULL)
            {first=prev;
            mid=root;}
            else
            last=root;
        }
        
        prev=root;
        swapVal(root->right);

    }
};