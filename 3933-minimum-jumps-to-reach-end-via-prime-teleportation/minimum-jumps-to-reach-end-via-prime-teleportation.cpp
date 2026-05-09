unordered_map<int,vector<int>> factors;
const int max_ele=1000001;
bool initialied=[](){for (int i = 2; i < max_ele; ++i) {
        if (factors[i].empty()) {
            for (int j = i; j < max_ele; j += i) {
                factors[j].push_back(i);
            }
        }
        }
        return true;
}();
class Solution {
public:
    int minJumps(vector<int>& nums) {
        unordered_map<int,vector<int>> edges;
        int max_ele=*max_element(nums.begin(),nums.end());
        
        
        // vector<vector<int>> factors(max_ele+1);
        

        int n=nums.size();

        for(int i=0;i<n;i++){
            for(int& p:factors[nums[i]]){
                edges[p].push_back(i);
            }
        }

        int res=0;
        vector<bool> seen(n,false);
        seen[0]=true;
        vector<int> q={0};
        while(true){
            vector<int> q2;
            for(int& i:q){
                if(i==n-1) return res;
                if(i>0 && !seen[i-1])
                {
                    seen[i-1]=true;
                    q2.push_back(i-1);
                }
                if(i<n-1 && !seen[i+1])
                {
                    seen[i+1]=true;
                    q2.push_back(i+1);
                }
                if(factors[nums[i]].size()==1)
                {
                    int p=nums[i];
                    if(edges.count(p))
                    {
                        for(int& j:edges[p])
                        {
                            if(!seen[j]){
                                seen[j]=true;
                                q2.push_back(j);
                            }
                        }
                        edges[p].clear();
                    }
                }
            }
            q=move(q2);
            res++;
        }

    }
};