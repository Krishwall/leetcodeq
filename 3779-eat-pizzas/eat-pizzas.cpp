class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        sort(pizzas.begin(),pizzas.end(),greater<int>());

        long long ans=0,totalDays=pizzas.size()/4,oddDays=(totalDays+1)/2;
        for(int i=0,day=1;day<=totalDays;++i,++day)
        {
            if(day>oddDays) 
                i++;
            ans+=pizzas[i];

        }
        return ans;
    }
};