class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int ans;
        int n=nums.size();
        int beg=*max_element(nums.begin(),nums.end());
        int end=accumulate(nums.begin(),nums.end(),0);
    while(beg<=end)
        {   int  grp=1;
            int mid= beg +(end-beg)/2;
            int totalsum=0;
            for(int i=0;i<n;++i)
            {   
                if (nums[i]+totalsum<=mid)
                    {
                        totalsum+=nums[i];
                    }
                else 
                {
                    grp++;
                    totalsum=nums[i];
                }
            }
            if (grp<=k)
                {
                    ans=mid;
                    end=mid-1;
                    
                }
            else beg=mid+1;
        }
    return ans;
    }
};