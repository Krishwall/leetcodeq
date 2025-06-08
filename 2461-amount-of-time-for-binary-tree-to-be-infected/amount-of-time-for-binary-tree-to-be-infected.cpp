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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> parent;
        unordered_map<TreeNode*,bool> visited;
        findParents(root,parent);
        TreeNode* target;
        findNode(root,start,target);
        queue<TreeNode*> q;
        visited[target]=true;
        q.push(target);
        int count=0;

        while(!q.empty())
        {   int fl=0;
            int sz=q.size();
           
            for(int i=0;i<sz;++i)
            {
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left && !visited[curr->left]){
                    fl=1;
                        q.push(curr->left);
                        visited[curr->left]=true;
                        
                    }
                    if(curr->right && !visited[curr->right]){
                        fl=1;
                        q.push(curr->right);
                        visited[curr->right]=true;

                    }
                    if(parent[curr] && !visited[parent[curr]])
                      {  fl=1;
                        q.push(parent[curr]);
                        visited[parent[curr]]=true;}
                }
               if(fl) count++;
            }
            return count;
        }


        
    
    void findNode(TreeNode* root,int start,TreeNode*& target)
    {   if(!root) return;
        if(root->val==start)
        {
            target=root;
            return ;
        }
        findNode(root->left,start,target);
        findNode(root->right,start,target);
    }

    void findParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent)
    {   queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())   
            {   auto a=q.front();
                q.pop();
                if(a->left)
            {
                parent[a->left]=a;
                q.push(a->left);
            }
            if(a->right)
            {
                parent[a->right]=a;
                q.push(a->right);
            }
            }
    }

};