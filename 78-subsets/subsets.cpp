class Solution {
public:
vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> sub={};
        backtrack(nums,0,sub);
        return ans;
    }
    void backtrack(vector<int>& nums,int idx ,vector<int>& sub)
    {
        if(idx== nums.size()){
            ans.push_back(sub);return ;}
        sub.push_back(nums[idx]);
        backtrack(nums, idx+1,sub);

        sub.pop_back();
        backtrack(nums,idx+1,sub);
    }
};