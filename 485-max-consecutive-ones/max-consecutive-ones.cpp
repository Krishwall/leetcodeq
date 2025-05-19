class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l=0,r=0,n=nums.size(),max1=0;
        while(r<n)
        {
            if(nums[r]==1 )
            r++;
            else
            {
            max1=max(max1,(r-l));
           r++; l=r;
            } max1=max(max1,(r-l));
        }return max1;
    }
};