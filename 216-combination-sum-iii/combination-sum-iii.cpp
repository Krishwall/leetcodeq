class Solution {
public:
vector<vector<int>> ans;
    vector<vector<int>> combinationSum3(int k, int n) {
            if(k<2 || k>9 || n<1 || n>60)
            return {};
            vector<int> sub;
           
            backtrack(1,k,n,sub);
            return ans;
        
    }

    void backtrack(int idx,int k, int target,vector<int> sub)
    {
        if (target==0 && k==0)
        {
            ans.push_back(sub);
            return;
        }
        if (k==0 || target<=0)
          {return ;}
         for (int i=idx;i<=9;i++) {
            sub.push_back(i);
            backtrack(i+1,k-1,target-i,sub);
            sub.pop_back();
         }
        
       

    }
};