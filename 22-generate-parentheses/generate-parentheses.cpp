class Solution {
public:
vector<string> ans;
    vector<string> generateParenthesis(int n) {
        ans.clear();
        string s="(";
        backtrack(n-1,n,s);
        return ans;
    }
    void backtrack(int left_p,int right_p, string &s)
        {
            if (!left_p && !right_p)
                {ans.push_back(s);
                return ;}
            if (left_p>0)
            {s.push_back('(');
            backtrack(left_p-1,right_p,s);
            s.pop_back();}
            if (left_p<right_p)
            {
                s.push_back(')');
                backtrack(left_p,right_p-1,s);
                s.pop_back();
            }
        }
        
};