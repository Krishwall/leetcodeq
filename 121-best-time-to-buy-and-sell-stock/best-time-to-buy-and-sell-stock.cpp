class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int mini=prices[0];
        int maxP=0;

        for(int i=1;i<prices.size();++i)
        {   int currP=prices[i]-mini;
            mini=min(mini,prices[i]);
            maxP=max(maxP,currP);
        }

        return maxP;
    }
};