class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        return func(nums,k,n) - func(nums,k-1,n);
    }

    int func(vector<int>& nums, int k,int n)
    {   map<int,int> mpp;
        int l=0,r=0,cnt=0;
        while(r<n)
        {
            mpp[nums[r]]++;

            while(mpp.size()>k)
            {
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0) mpp.erase(nums[l]);
                 l++;   

            }
           cnt+=r-l+1;
            r++;
            
        }   
        return cnt;
    }
};