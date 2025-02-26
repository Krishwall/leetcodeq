class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n= nums.size();
        int currsum=0;
        int minsum=INT_MAX;
        int maxsum=INT_MIN;
       
        for (int i=0;i<n;++i)
        {
            currsum+=nums[i];
            maxsum=max(maxsum,currsum);
            if (currsum<0)
                currsum=0;
        }
        currsum=0;
        for (int i=0;i<n;++i)
        {
            currsum+=nums[i];
            minsum=min(minsum,currsum);
            if (currsum>0)
                currsum=0;
        }
        return max(abs(minsum),maxsum);
        
    return 1;
    }
};