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
    int minCameraCover(TreeNode* root) {
        int ans=0;
        unordered_set<TreeNode*> covered;
        covered.insert(NULL);
        minCam(root,NULL,covered,ans);
        return ans;
        
    }

private:
        void minCam(TreeNode* node,TreeNode* par,unordered_set<TreeNode*>& covered, int& ans)
        {
            if(node!=NULL){
                minCam(node->left,node,covered,ans);
                minCam(node->right,node,covered,ans);

                if(par==NULL && covered.find(node)==covered.end()
                    || covered.find(node->left)==covered.end() || 
                    covered.find(node->right)==covered.end())
                    {
                        ans++;
                        covered.insert(node);
                        covered.insert(par);
                        covered.insert(node->left);
                        covered.insert(node->right);

                    }
            }
        
        }
};