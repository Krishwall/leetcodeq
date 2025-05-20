class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size(),l=0,r=0;
        vector<int> ans(n,0);

        for(int i=0;i<n;++i)
        {
            if(nums[i]>0)
            {ans[l*2]=nums[i];l++;}
            else
            {ans[r*2+1]=nums[i];r++;}
            
        }return ans;
    }
};