class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int pref=1,suff=1,maxi=-11;
       int n=nums.size();
        for(int i=0;i<n;++i)
        {   if(pref==0) pref=1;
            if(suff==0)  suff=1;

            pref=pref*nums[i];
            suff=suff*nums[n-i-1];
            maxi=max(maxi,max(pref,suff));
        }   
        return maxi;
    }
};