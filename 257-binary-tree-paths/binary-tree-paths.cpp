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
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> ans;
            string temp="";
            allPaths(root,temp,ans);
            return ans;

		}
        void allPaths(TreeNode* root, string temp, vector<string>& ans) {
        if(!root) return;

        if(!temp.empty())
            temp += "->";

        temp += to_string(root->val);

        if(!root->left && !root->right) {
            ans.push_back(temp);
            return;
        }

        allPaths(root->left, temp, ans);
        allPaths(root->right, temp, ans);
    }
};