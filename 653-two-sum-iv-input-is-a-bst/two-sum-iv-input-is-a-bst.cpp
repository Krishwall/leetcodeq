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
stack<TreeNode*> st_back;
stack<TreeNode*> st_front;
    bool findTarget(TreeNode* root, int k) {
pushLeft(root);
pushRight(root);

int a=next();
int b=before();
    while((a != b) && hasNext(st_back) && hasNext(st_front) )
    {
        if(a+b==k) return true;
        if(a+b<k)
            a=next();
        else if(a+b>k) b=before();
        
    }
    return false;
    }


    int next() {
        TreeNode* temp=st_front.top();
        st_front.pop();
    
        pushLeft(temp->right);
        return temp->val;
        
    }
    
    bool hasNext(stack<TreeNode*> st) {
        return (!st.empty());
        
    }
    void pushLeft(TreeNode* root)
    {
        while(root!=NULL)
        {
            st_front.push(root);
            root=root->left;
        }
    }
    int before()
    {
        TreeNode* tmp=st_back.top();
        st_back.pop();
        pushRight(tmp->left);
        return tmp->val;


    }

    void pushRight(TreeNode* root)
    {
        while(root)
        {
            st_back.push(root);
            root=root->right;
        }
    }

};