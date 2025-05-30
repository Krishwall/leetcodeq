class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        int farthest=0;
        int r=0,l=0,jumps=0;
        while(r<n-1)
        {
            // farthest=0;
            for(int  idx=l;idx<=r;++idx)
            {
                farthest=max(farthest,idx+nums[idx]);
            }
            
            l=r+1; jumps++;
            r=farthest;
        }
        return jumps;
    }
};