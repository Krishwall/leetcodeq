class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> parent(n);
        vector<int> dp(n,0);
        int maxi=0;
        int last_idx=0;
        for(int i=0;i<n;++i)
        {   parent[i]=i;
            for(int prev_ele=0;prev_ele<i;++prev_ele)
            {if(nums[i]%nums[prev_ele]==0 && dp[i]<dp[prev_ele]+1)
            {
                dp[i]=dp[prev_ele]+1;
                
                parent[i]=prev_ele;
            }
            }
            if(dp[i]>maxi)
            {
                maxi=dp[i];
                last_idx=i;
            }
        }
    vector<int> ans;


	ans.push_back(nums[last_idx]);
	while(parent[last_idx]!=last_idx){
		last_idx=parent[last_idx];
		ans.push_back(nums[last_idx]);

	}
    return ans;

    }
};