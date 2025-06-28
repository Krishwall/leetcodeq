class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        
        int prev=nums[0],prev2=0;int pick,npick;
        for(int i=1;i<n;++i)
        {   if(i>1)
                pick=nums[i]+prev2;

            else pick=nums[i];
                npick=0+prev;
            int curi=max(pick,npick);
            prev2=prev;
            prev=curi;
        }
        return prev;
    }
};