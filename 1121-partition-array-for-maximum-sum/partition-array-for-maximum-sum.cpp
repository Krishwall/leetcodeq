class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,0);

        for(int i=n-1;i>=0;--i)
        {   int maxAns=INT_MIN;
            int maxiele=INT_MIN;
            int len=0;
            for(int j=i;j<min(n,i+k);++j)
            {   len++;
                maxiele=max(maxiele,arr[j]);
                int maxi= len*maxiele +dp[j+1];
                maxAns=max(maxAns,maxi);
            }
            dp[i]=maxAns;
        }
        return dp[0];
    }
};