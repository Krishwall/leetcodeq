class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int mid;
        int low=0;
        int high=nums.size();

        if(target<nums[0]) return 0;
        if(target>nums[high-1])return high;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(target>nums[mid] && target<nums[mid+1]) return mid+1;
            if(nums[mid]==target)
                return mid;
            if(target<nums[mid])
                high=mid-1;
            else if(target>nums[mid])
                low=mid+1;
        }
        return mid;
    }
};