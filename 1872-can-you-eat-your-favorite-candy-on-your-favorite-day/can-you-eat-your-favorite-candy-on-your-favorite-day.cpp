class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int n=candiesCount.size();
        int q=queries.size();
        vector<bool> ans(q);
        vector<long long> prefixSum(n);
        prefixSum[0]=candiesCount[0];
        for(int i=1;i<n;i++)
        {
            prefixSum[i]=prefixSum[i-1] +candiesCount[i];
        }

        for(int i =0;i<q;i++)
        {
            auto type=queries[i][0];
            auto day=queries[i][1];
            auto cap=queries[i][2];

            auto minCan=(day+1);
            long long maxCan=1ll*(day+1)*cap;
            auto start=type==0?1:(prefixSum[type-1]+1);
            auto end=prefixSum[type];
            if(maxCan>=start && minCan<=end)
            ans[i]=true;
            else ans[i]=false;
        }

        return ans;
    }
};