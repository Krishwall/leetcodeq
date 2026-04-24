class Solution {
private:
    int helper(vector<int>& nums,int k)
    {
        unordered_map<int,int>  numFreq;
        // unordered_set<int> set;
        int subCount=0;
        int n=nums.size();
        int l=0,r=0;
        while(r<n) 
        {
            numFreq[nums[r]]++;
            
            while(numFreq.size()>k)
            {
                numFreq[nums[l]]--;
                if(numFreq[nums[l]]==0)
                    numFreq.erase(nums[l]);
                ++l;
            }
            subCount+=(r-l+1);
            r++;

        }

        return subCount;
    }
public:

    int subarraysWithKDistinct(vector<int>& nums, int k) {

        return helper(nums,k)-helper(nums,k-1);
        
    }
};