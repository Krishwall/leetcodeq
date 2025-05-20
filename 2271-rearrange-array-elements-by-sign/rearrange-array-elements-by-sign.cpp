class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size(),l=0,r=1;
        vector<int> ans(n,0);

        for(int i=0;i<n;++i)
        {
            if(nums[i]>0)
            {ans[l]=nums[i];l=l+2;}
            else
            {ans[r]=nums[i];r=r+2;}
            
        }return ans;
    }
};