class Solution {
public:
    int numDecodings(string s) {
        int i=0,n=s.size();
       
        
        // dp[0]=1;
        // dp[1]=1;
        int curr=1;
        int prev=-1,follow=-1;
        for(int i=n-1;i>=0;i--)
        {   if(s[i]=='0')
            prev=0;
            else
            {   prev=curr;
                if(i+1<n)
                {
                    int num=(s[i]-'0')*10 +(s[i+1]-'0');
                    if(num>=10 && num<=26)
                    {
                        prev+=follow;
                    }
                }
            }
            follow=curr;
            curr=prev;

        }
        return prev;
       
        
    }
    // int backtrack(int i,string s,int n,vector<int> dp)
    // {   if(i==n)
    //     {
    //     return 1;}
    //     if(s[i]=='0')
    //     return 0;
    //     if(dp[i]!=-1) return dp[i];
    //     int ways=backtrack(i+1,s,n,dp);

    //     if(i+1<n)
    //     {
    //         int num=(s[i]-'0')*10+(s[i+1]-'0');
    //         if(num>=10 && num<=26)
    //         ways+=backtrack(i+2,s,n,dp);
    //     }
    //     return dp[i]=ways;
    // }
};