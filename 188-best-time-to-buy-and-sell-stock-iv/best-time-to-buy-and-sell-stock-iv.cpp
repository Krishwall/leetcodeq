class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n=prices.size();

        vector<vector<int>> dp(n+1,vector<int>(k*2+1,0));

        for(int i=n-1;i>=0;--i)
        {
            for(int buy0sell1=2*k-1;buy0sell1>=0;--buy0sell1)
                {
                    if(buy0sell1%2==0)
                    dp[i][buy0sell1]=max(-prices[i]+dp[i+1][buy0sell1+1],0+dp[i+1][buy0sell1]);
                    else
                    dp[i][buy0sell1]=max(prices[i]+dp[i+1][buy0sell1+1],0+dp[i+1][buy0sell1]);
                }
            
        }
        return dp[0][0];
    }
};