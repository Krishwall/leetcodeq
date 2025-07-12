class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();

        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        for(int i=n-1;i>=0;--i)
        {
            for(int prev_ind=i-1;prev_ind>=-1;--prev_ind)
            {
                int len=0+dp[i+1][prev_ind+1];

                if(prev_ind==-1 || nums[i]>nums[prev_ind])
                len=max(len,1+dp[i+1][i+1]);
                
            dp[i][prev_ind+1]=len;
            }
        }
        return dp[0][0];
    }
};