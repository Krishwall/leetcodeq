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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        map<int,pair<int,int>> hash;
    rightSide(root,hash,0,0);
    for(auto& a:hash)
        ans.push_back(a.second.second);
    return ans;
    }

    void rightSide(TreeNode* root,map<int,pair<int,int>>& hash,int idx,int depth)
    {
        if(!root) return;
        if( hash.find(depth)==hash.end() )
            {hash[depth]={idx,root->val};}
        rightSide(root->right,hash,idx+1,depth+1);
        rightSide(root->left,hash,idx-1,depth+1);
    }
};