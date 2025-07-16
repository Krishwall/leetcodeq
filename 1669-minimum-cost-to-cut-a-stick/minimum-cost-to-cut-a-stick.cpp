class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        sort(cuts.begin(),cuts.end());
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        vector<vector<long long>> dp(c+2,vector<long long>(c+2,0));

        for(int i=c;i>0;--i)
        {
            for(int j=i;j<=c;++j)
            {   
                long long mini=LONG_MAX;
                for(int k=i;k<=j;++k)
                {
                    long long cost=cuts[j+1]-cuts[i-1]+dp[i][k-1]+dp[k+1][j];
                    mini=min(cost,mini);
                }
                dp[i][j]=mini;
            }
        }
        return dp[1][c];
    }
};