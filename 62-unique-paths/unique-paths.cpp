class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n,0);
        
        for(int i=0;i<m;++i)
        {   vector<int> col(n,0);
            for(int j=0;j<n;++j)
            {
                if(i==0 && j==0) col[j]=1;
                else{   int up=0,left=0;
                   if(i>0) up=dp[j];
                   if(j>0) left=col[j-1];
                   col[j]=up+left;
                }
            }dp=col;
        }return dp[n-1];
        
    }

    
};