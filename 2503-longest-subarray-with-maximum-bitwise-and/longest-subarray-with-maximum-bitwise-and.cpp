class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        auto maxel=max_element(nums.begin(),nums.end());
        int a=1,c=0;

        for (int num:nums)
        {
            if (num==*maxel)
            {
                c+=1;
            if (c>a)
                a=c;
            }
            else 
                c=0;
        }
        return a;
        
    }
};