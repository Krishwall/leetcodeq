class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int beg=0;
        int n=nums.size();
        int end=n-1;
        int mid;
        while (beg <=end)
        {   mid=(beg+end)/2;
        if (nums[mid]==target) return true;
        if (nums[beg] == nums[mid] && nums[mid] == nums[end]) {
            beg = beg + 1;
            end = end - 1;
            continue;
        }
        if (nums[beg]<=nums[mid]){
            if ( target <=nums[mid] && target >=nums[beg] )
                end=mid-1;
            
            else 
                beg=mid+1;
        }
        else 
        {
            if ( nums[mid]<=target && target <= nums[end])
                beg=mid+1;

            else 
                end=mid-1;
        }
        }

        return false;

    }
};