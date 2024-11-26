class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        
        vector<int> num(n,0);

        for(auto&i: edges)
        {
            num[i[1]]=1;
        }
        if (accumulate(num.begin(),num.end(),0)<n-1)
            return -1;
        else 
        return distance(num.begin(),find(num.begin(),num.end(),0));
        
    }
};