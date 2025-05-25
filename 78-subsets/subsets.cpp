class Solution {
public:
vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int n=nums.size();
        int subsets=1<<n;
        for(int i=0;i<subsets;++i)
        {vector<int> sub;
            for(int j=0;j<n;++j)
                {
                    if (i &(1<<j) )
                        sub.emplace_back(nums[j]);
                }
                ans.emplace_back(sub);
        }
        return ans;
    }

    
};