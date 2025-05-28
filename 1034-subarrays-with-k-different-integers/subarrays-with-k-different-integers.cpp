class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        return func(nums,k,n) - func(nums,k-1,n);
    }

    int func(vector<int>& nums, int k,int n)
    {   
        int l=0,r=0,cnt=0,ans=0;
        vector<int> hash(n+1,0);
        while(r<n)
        {
            hash[nums[r]]++;
            if(hash[nums[r]]==1) cnt++;
            while(cnt>k)
            {
                hash[nums[l]]--;
                if(hash[nums[l]]==0) cnt--;
                 l++;   

            }
           ans+=r-l+1;
            r++;
            
        }   
        return ans;
    }
};