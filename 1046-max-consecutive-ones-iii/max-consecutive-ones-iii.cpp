class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int l=0,r=0,n=nums.size(),zeros=0,maxL=0;
        while(r<n)
        {
            if(nums[r]==0) zeros++;
            if(zeros>k)
            {
                if(nums[l]==0) zeros--;
                l++;
            }
            if (zeros<=k) maxL=max(maxL,r-l+1);
            r++;
        }
        return maxL;
    }
};