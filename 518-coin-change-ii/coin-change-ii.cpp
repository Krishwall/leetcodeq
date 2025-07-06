class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<long>> dp(n,vector<long>(amount+1,0));
        long limit=1e11;
        for (int i = 0; i <= amount; i++) {
        if (i % coins[0] == 0)
            dp[0][i] = 1;}
        

        for(int i=1;i<n;++i)
        {
            for(int T=0;T<=amount;++T)
            {
                long notPick=dp[i-1][T];
                long pick=0;
                if(coins[i]<=T) 
                    pick=dp[i][T-coins[i]];
            if(pick+notPick>limit) return 0;
                dp[i][T]=pick+notPick;
            }
        }
        return dp[n-1][amount];
        
    }
};