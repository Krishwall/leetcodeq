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
    int height(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int l = height(root->left);
        int r = height(root->right);
        return 1 + max(l, r);
    }
    void findNode(TreeNode* root,TreeNode*& target,int start)
    {   if(!root) return;
        if(root->val==start)
        {
            target=root;
            return ;
        }
        findNode(root->left,target,start);
        findNode(root->right,target,start);
    }
    int burn(TreeNode* root, int start, int &timer) {
        if (!root) {
            return 0;
        }
        if (root->val == start) {
            return -1;
        }
        int left = burn(root->left, start, timer);
        int right = burn(root->right, start, timer);
        if (left < 0) {
            timer = max(timer, abs(left) + right);
            return left - 1;
        }
        if (right < 0) {
            timer = max(timer, abs(right) + left);
            return right - 1;
        }
        return 1 + max(left, right);
    }
    int amountOfTime(TreeNode* root, int start) {
        int timer = 0;
        burn(root, start, timer);
        TreeNode* burnNode = NULL;
        findNode(root, burnNode,start);
        int h = height(burnNode)-1;
        return max(h, timer);
        }


        
    

    // void findParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent)
    // {   queue<TreeNode*>q;
    //     q.push(root);
    //     while(!q.empty())   
    //         {   auto a=q.front();
    //             q.pop();
    //             if(a->left)
    //         {
    //             parent[a->left]=a;
    //             q.push(a->left);
    //         }
    //         if(a->right)
    //         {
    //             parent[a->right]=a;
    //             q.push(a->right);
    //         }
    //         }
    // }

};