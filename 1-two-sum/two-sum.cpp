class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hasmap;
        for(int i=0;i<nums.size();++i)
        {
            int rem=target-nums[i];
            if(hasmap.find(rem) != hasmap.end())
            {
                return {hasmap[rem],i};
            }
            else
            hasmap[nums[i]]=i;
        }
        return {};
        
    }
};