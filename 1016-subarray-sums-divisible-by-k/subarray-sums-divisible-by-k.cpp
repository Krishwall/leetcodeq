class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int prefixSum=0;
        unordered_map<int,int> remCount;
        int result=0;
        remCount[0]=1;

        for(int i=0;i<n;i++)
        {
            prefixSum+=nums[i];
            int rem=prefixSum%k;
            if(rem<0)
            rem+=k;
            
            
            if(remCount.find(rem)!=remCount.end())
            {result+=remCount[rem];
            }
            ++remCount[rem];
        }

        return result;
        
    }
};