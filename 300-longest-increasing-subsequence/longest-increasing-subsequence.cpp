class Solution {
public:
    // int recursiveAlgo(int ind,int prev_ind,vector<int> nums)
    // {
    //     if(ind==n) return 0;

    //     int len=0+recursiveAlgo(ind+1,prev_ind);
    //     if(prev_ind==-1 || nums[ind]>nums[prev_ind])
    //     len=max(len,1+recursiveAlg(ind+1,ind,nums));
    // }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();

        vector<int> temp;int len=1;
        temp.push_back(nums[0]);
        for(int i=1;i<n;++i)
        {
            if(nums[i]>temp.back())
           { temp.push_back(nums[i]); len++;}
            else
            {int insert_idx=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
            temp[insert_idx]=nums[i];}
        }
        return len;
    }
};