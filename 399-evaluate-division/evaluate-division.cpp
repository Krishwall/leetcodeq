class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>> edgesW;

        for(int i=0;i<equations.size();i++)
        {
            edgesW[equations[i][0]].push_back({equations[i][1],values[i]});
            edgesW[equations[i][1]].push_back({equations[i][0],(1.0/values[i])});
        }

        vector<double> ans;

        for(auto&   a: queries)
        {   
            auto dividend=a[0];
            auto divisor=a[1];
            if(edgesW.find(dividend)==edgesW.end() || edgesW.find(divisor)==edgesW.end())
            {ans.push_back(-1.0);
            continue;}

            unordered_set<string> visited;
            double result=dfs(dividend,divisor,edgesW,visited,1.0);
            ans.push_back(result);
        }

        return ans;

    }

    double dfs(string& src, string& dest,unordered_map<string,vector<pair<string,double>>>& edgesW,
    unordered_set<string>& visited ,double product)
    {
        if(edgesW.find(src)==edgesW.end())
            return -1.0;
        if(src==dest)
                return product;
        
        visited.insert(src);

        for(auto& neighbour:edgesW[src])
        {
            string next=neighbour.first;
            double weight=neighbour.second;
            if(visited.find(next)==visited.end()){
                double result=dfs(next,dest,edgesW,visited,product*weight);
                if(result!=-1.0)
                    return result;
            }
        }
        return -1.0;
    }

    
};