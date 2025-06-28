class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        dp[0]=nums[0];int pick,npick;
        for(int i=1;i<n;++i)
        {   if(i>1)
             pick=nums[i]+dp[i-2];
             else pick=nums[i];
             npick=0+dp[i-1];
            dp[i]=max(pick,npick);
        }
        return dp[n-1];
    }
};