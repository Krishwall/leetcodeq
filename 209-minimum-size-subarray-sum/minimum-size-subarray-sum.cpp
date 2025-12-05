class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int low=1, high=nums.size(),mn=0;
        int n=high;
        while(low<=high){
            int mid=(low+high)/2;

            if(windowFind(mid,nums,target,n)){
                high=mid-1;
                mn=mid;
            }else low=mid+1;
        }
        return mn;
    }

    bool windowFind(int size, vector<int>& nums,int& target,int& n)
    {
        int sum=0;int i=0,j=0;
        int mx=INT_MIN;
        while(j<n)
        {
            sum+=nums[j];
            if(j-i+1==size){
                mx=max(sum,mx);
                sum-=nums[i];
                i++;
                }
                j++;
            }

        if(mx>=target)
        return true;
        return false;
        }
    
};