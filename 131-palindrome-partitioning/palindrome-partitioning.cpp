class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> partition(string s) {
        vector<string>  comb;
        backtrack(0,s,comb,s.size());
        return ans;
        
    }

    void backtrack(int idx, string s, vector<string>& comb,int len)
        {
            if(idx==len)
            {ans.push_back(comb);
                return;
            }

        for(int i=idx;i<len;++i)
        {
            if(isPalindrome(s,idx,i))
            {
                comb.push_back(s.substr(idx,i-idx+1));
                backtrack(i+1,s,comb,len);
                comb.pop_back();
            }
        }
        }

        bool isPalindrome(string s, int start, int end){
            while(start<=end)
            {
                if(s[start++]!=s[end--])
                    return false;
            }
            return true;
        }
};