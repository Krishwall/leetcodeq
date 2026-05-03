class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> pre(n,0);
        vector<int> suffi(n,0);

        for(int i=0;i<n-1;i++)
        {
            long diffFromRight=nums[i+1]-nums[i];
            long diffFromLeft=(i>0)? nums[i]-nums[i-1]:LONG_MAX;
            pre[i+1]=pre[i]+((diffFromRight<diffFromLeft)?1:diffFromRight);

        }
        for(int i=n-1;i>0;i--)
        {
            long diffFromRight=(i<n-1)?nums[i+1]-nums[i]:LONG_MAX;
            long diffFromLeft= nums[i]-nums[i-1];
            suffi[i-1]=suffi[i]+((diffFromRight>=diffFromLeft)?1:diffFromLeft);
        }
        vector<int> ans;
        for(auto& it: queries)
        {   
            int l=it[0];
            int r=it[1];
            if(l<=r)    ans.push_back(pre[r]-pre[l]);
            else ans.push_back(suffi[r]-suffi[l]);
        }

        return ans;
       
    }
};