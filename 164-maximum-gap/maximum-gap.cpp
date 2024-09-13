class Solution {
public:
    int maximumGap(vector<int>& nums) {
        auto n=nums.size();
        if (n<2)
        return 0;
        sort(nums.begin(),nums.end());
        int maxi=0;
        for(auto i=0;i<n-1;i++)
            {
                maxi=max(maxi,nums[i+1]-nums[i]);
            }
        return maxi;
    }
};