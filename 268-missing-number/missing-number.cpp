class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int xr=0;
        int arrxr=0;
        int n=nums.size();
        for(int i=1;i<=n;i++)
        {
            xr=xr^i^nums[i-1];
            // arrxr=arrxr^nums[i-1];
        }
        return xr;

    }
};