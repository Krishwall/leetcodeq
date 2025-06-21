class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int high = *max_element(nums.begin(),nums.end());
        cout<<high;
        int low=1;
        int sum=0,ans=INT_MAX;;

        while(low<=high){
            sum=0;
            int mid=(low+high)/2;
            for(int i=0;i<n;++i)
            sum+= ceil(double(nums[i])/mid);

            // if(sum==threshold) return mid;
            if(sum<=threshold)
                {ans=min(mid,ans);
                    high=mid-1;}
            else
                low=mid+1;
        }
        return ans;
    }
};