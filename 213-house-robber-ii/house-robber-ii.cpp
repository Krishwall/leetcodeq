class Solution {
public:
    int helpTheRobber(vector<int>& nums) {
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
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> num1;
        vector<int> num2;
        if(n==1) return nums[0];
        for(int i=0;i<n;++i)
        {
            if(i!=0)num1.push_back(nums[i]);
            if(i!=n-1) num2.push_back(nums[i]);
        }
        return max(helpTheRobber(num1),helpTheRobber(num2));


    }
};