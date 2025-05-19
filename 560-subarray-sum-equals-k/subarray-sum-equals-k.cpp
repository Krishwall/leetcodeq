class Solution {
public:
int ans=0;
    int subarraySum(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();++i){
                backtrack(i,nums,0,k);
        }
    
        return ans;
    }

    void backtrack(int idx,vector<int>& nums , int sum,int k)
    {
        if(idx>=nums.size() )
        
            return;
       sum+=nums[idx];
        
        if (sum==k)
       { ans++;}
            
        
                backtrack(idx+1,nums,sum,k);
        }
        
    
};