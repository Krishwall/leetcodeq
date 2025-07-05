class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        for(int t=0;t<=amount;++t)
        {
            if(t%coins[0]==0) dp[0][t]=t/coins[0];
            else
            dp[0][t]=1e9 ;
        }
        for(int i=1;i<n;++i)
        {
            for(int t=0;t<=amount;++t)
            {
                int notTake=0+dp[i-1][t];
                int take=INT_MAX;
                if(t-coins[i]>=0)
                take=1+dp[i][t-coins[i]];
                dp[i][t]=min(take,notTake);
            }
        }

        return dp[n-1][amount]>=1e9?-1:dp[n-1][amount];

    

    
        
    }
};