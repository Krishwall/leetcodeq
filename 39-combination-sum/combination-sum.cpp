class Solution {
public:
vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int> comb;
        backtrack(0,candidates,comb,target,candidates.size());
        return ans;
    }

    void backtrack(int idx,vector<int>& candidates,vector<int>& comb, int target,int n)
    {if (idx==n)
        {
            if (target==0)
            ans.push_back(comb);
        return ;
        }
    if (candidates[idx]<=target)
   { comb.push_back(candidates[idx]);
    backtrack(idx,candidates,comb,target-candidates[idx], n);
    comb.pop_back();}
    backtrack(idx+1,candidates,comb,target, n);
   

    }
};