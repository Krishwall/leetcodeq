class Solution {
public:
    vector<string> ans;
    vector<string> letterCombinations(string digits) {
        int len =digits.length();
        if (len==0)
        return {};
        string comb;

        vector<string> dialpad={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        backtrack(digits,len,dialpad,comb,0);
        return ans;
    }
    void backtrack(string digits,int len,vector<string>& dialpad, string& comb,int idx )
    {   
        if(idx==len)
            {ans.push_back(comb);
            return;}
        
        for(int pos=0;pos<dialpad[(digits[idx] - '0')].length();++pos)
       { comb.push_back(dialpad[(digits[idx] - '0')][pos]);
        backtrack(digits,len,dialpad,comb,idx+1);
        comb.pop_back();}
          
        
    }
};