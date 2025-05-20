class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size(),l=0,r=0;
        vector<int> ans(n,0);

        for(int num:nums)
        {
            if(num>0)
            {ans[l*2]=num;l++;}
            else
            {ans[r*2+1]=num;r++;}
            
        }return ans;
    }
};