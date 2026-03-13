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
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<TreeNode*>> dp;

        return generate(1,n,dp);
    }
    vector<TreeNode*> generate(int left,int right,vector<vector<TreeNode*>> dp)
    {
        if(left> right)
            return {NULL};
        vector<TreeNode*> res;
        for (int val=left;val<=right;val++)
        {
            for (auto& leftTree: generate(left,val-1,dp))
                {
                    for(auto& rightTree:generate(val+1,right,dp))
                    {
                        auto root=new TreeNode(val,leftTree,rightTree);
                        res.push_back(root);
                    }
                }
        }
        return res;
    }
};