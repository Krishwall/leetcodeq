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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* in= new TreeNode(val);
        if(!root) return in;
        auto head=root;
        while(head)
        {
            if(val<head->val)
            { if(head->left==NULL)
                {head->left=in;break;}
                head=head->left;
            }
            else 
            {   if(head->right==NULL)
                {head->right=in;break;}
                head=head->right;}
            
        }
        return root;
        
    }
};