class Solution {
public:
int ans=0;
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> hashMap;
    int ans=0,sum=0;
        for(int i=0;i<nums.size();++i)

        {   sum+=nums[i];
           if(sum==k)
                ans++;

            long long rem=sum-k;
            if(hashMap.find(rem) != hashMap.end())
                ans+=hashMap[rem];

            
            if(hashMap.find(sum)==hashMap.end())
                hashMap[sum]=1;
            else  hashMap[sum]+=1;
        }
        return ans;
    }

    
        
    
};