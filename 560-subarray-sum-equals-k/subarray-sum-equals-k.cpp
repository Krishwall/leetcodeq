class Solution {
public:
int ans=0;
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> hashMap;
    int ans=0,sum=0;hashMap[0] = 0; 
        for(int i=0;i<nums.size();++i)

        {   sum+=nums[i];
           if(sum==k)
                ans++;

            long long rem=sum-k;
            if(hashMap.find(rem) != hashMap.end())
                ans+=hashMap[rem];

            
            hashMap[sum]+=1;
        }
        return ans;
    }

    
        
    
};