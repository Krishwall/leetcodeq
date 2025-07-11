class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        // vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        vector<vector<int>> ahead(2,vector<int>(3,0)),cur(2,vector<int>(3,0));
        for(int i=prices.size()-1;i>=0;--i)
        {
            for(int buy=0;buy<2;++buy)
            {
                for(int cap=1;cap<=2;++cap)
                { if(buy)
                    cur[buy][cap]=max(-prices[i]+ahead[0][cap],0+ahead[1][cap]);
                    else
                    cur[buy][cap]=max(+prices[i]+ahead[1][cap-1],0+ahead[0][cap]);
            
                }
            }
            ahead=cur;
        }
        return ahead[1][2];
    }
};