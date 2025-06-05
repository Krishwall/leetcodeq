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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        unordered_map<int,vector<vector<int>>> hash;
        vector<vector<int>> ans;
        int mini=INT_MAX;int maxi=INT_MIN;
        traversal(hash,root,0,mini,maxi,0);
        for(int i=mini;i<=maxi;++i)
        {
            auto a = hash[i];
            sort(a.begin(),a.end());
            vector<int> temp;int k=0;
            while(k<a.size())
                {temp.push_back(a[k][1]);
                k++;}
            ans.push_back(temp);
        }
        return ans;



    }
    void traversal(unordered_map<int,vector<vector<int>>>& hash, TreeNode* root,int idx,int& mini,int& maxi,int top)

    {       if(root) 
                {(hash[idx]).push_back({top,root->val});
                mini=min(mini,idx);maxi=max(maxi,idx);
                
                    
            traversal(hash,root->left,idx-1,mini,maxi,top+1);
            top--;
            traversal(hash,root->right,idx+1,mini,maxi,top+1);
            top--;}

    }
};