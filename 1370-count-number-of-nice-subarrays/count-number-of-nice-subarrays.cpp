class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return func(nums,k) - func(nums,k-1);
    } 

    int func(vector<int>& nums , int k)
    {   if(k<0) return 0;
        int l=0,r=0,sum=0,n=nums.size(),arr_cnt=0;
        
        while(r<n)
        {   
            sum=sum+(nums[r]&1);
            while(sum>k)
            {      sum=sum-(nums[l]&1);
                l++;    
                
            }
            arr_cnt=arr_cnt+(r-l)+1;
            r++;

        }
        return arr_cnt;

    }
};