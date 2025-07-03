class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);

        if(sum&1 )  return false;

        int s1=sum/2;
        int n=nums.size();
        vector<vector<bool>> dp(n,vector<bool>(s1+1,0));

        for(int i=0;i<n;++i) dp[i][0]=true;
        if(nums[0]>s1+1) return false;
        dp[0][nums[0]]=true;

        for(int i=1;i<n;++i)
        {
            for(int target=1;target<=s1;++target)
            {
                bool notTake=dp[i-1][target];
                bool take=false;

                if(nums[i]<=target) take=dp[i-1][target-nums[i]];

                dp[i][target] = take|notTake;
            }
        }

        return dp[n-1][s1];

    }
};