class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> comb;
        backtrack(0,candidates,comb,target,candidates.size());
        return ans;
    }
    void backtrack(int idx,vector<int>& candidates,vector<int>& comb, int target,int n)
   
        {
            if (target==0)
            {  ans.push_back(comb);
        return ;
        }
        for (int i = idx; i < candidates.size(); i++) {
            if (i > idx && candidates[i] == candidates[i - 1]) continue;
            if (candidates[i]>target) break;
            comb.push_back(candidates[i]);
            backtrack(i+1,candidates,comb,target-candidates[i], n);
            comb.pop_back();
    
   
                }
    }
};