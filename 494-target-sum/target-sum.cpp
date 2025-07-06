class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();

        int totsum=accumulate(nums.begin(),nums.end(),0);
        if (totsum < abs(target) || (totsum + target) % 2 != 0)
            return 0;
        int s1=(totsum+target)/2;
        vector<vector<int>> dp(n,vector<int>(s1+1,0));

        for(int i=0;i<n;++i) dp[i][0]=1;

        if(nums[0]==0) dp[0][0]=2;
        else if(nums[0]<=s1 ) dp[0][nums[0]]=1;

        for(int i=1;i<n;++i)
        {
            for(int T=0;T<=s1;++T)
            {
                int notPick=dp[i-1][T];
                int pick=0;
                if(nums[i]<=T) 
                    pick=dp[i-1][T-nums[i]];
                dp[i][T]=pick+notPick;
            }
        }
        return dp[n-1][s1];

    }
};