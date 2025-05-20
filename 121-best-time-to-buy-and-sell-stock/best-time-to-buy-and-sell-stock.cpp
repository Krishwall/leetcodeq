class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minp=prices[0];
        int maxP=0;
        int cost;
        for(int i=1;i<prices.size();++i)
        {
            cost=prices[i]-minp;
            maxP=max(maxP,cost);
            minp=min(minp,prices[i]);
                    }
        return maxP;
    }
};