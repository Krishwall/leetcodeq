class Solution {
public:
    int minCut(string s) {
        int n=s.length();
        vector<int> dp(n+1,0);

        for(int i=n-1;i>=0;--i)
        {   string temp="";
            int mini=INT_MAX; 
            for(int j=i;j<n;++j)
            {   
                temp+=s[j];

                if(ispallindrome(temp))
                {
                    int part=1+dp[j+1];
                    mini=min(mini,part);
                }
            }
            dp[i]=mini;
        }
        return dp[0]-1;
    }
    bool ispallindrome(string& s)
    {
        int i=0;
        int j=s.size()-1;

        while(i<j)
        {
            if(s[i++]!=s[j--])return false;
        }
        return true;

    }
};