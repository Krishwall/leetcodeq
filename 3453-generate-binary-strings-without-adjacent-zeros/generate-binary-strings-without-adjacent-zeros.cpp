class Solution {
public:
vector<string> res;
    vector<string> validStrings(int n) {
        res.clear();
        string a="0",b="1";
        backtrack(0,a,n);
        backtrack(1,b,n);
        return res;
        
    }
    void backtrack(int prev, string &str,int n)
    {
        if (str.length()==n)
            {res.push_back(str);
            return ;
            }
        str.push_back('1');
        backtrack(1,str,n);
        str.pop_back();
        if (prev==1){
            str.push_back('0');
            backtrack(0,str,n);
            str.pop_back();
        }
    }
};