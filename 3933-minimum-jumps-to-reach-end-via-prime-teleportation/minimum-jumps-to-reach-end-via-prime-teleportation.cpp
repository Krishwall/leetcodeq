const int MAX = 1000001;

vector<vector<int>> factors(MAX);

bool initialized = []() {

    for(int i = 2; i < MAX; i++)
    {
        if(factors[i].empty())
        {
            for(int j = i; j < MAX; j += i)
            {
                factors[j].push_back(i);
            }
        }
    }

    return true;

}();

class Solution {
public:

    int minJumps(vector<int>& nums) {

        int n = nums.size();

        if(n == 1) return 0;

        unordered_map<int, vector<int>> edges;

        // factor -> indices
        for(int i = 0; i < n; i++)
        {
            for(int p : factors[nums[i]])
            {
                edges[p].push_back(i);
            }
        }

        queue<int> q;
        q.push(0);

        vector<bool> seen(n, false);
        seen[0] = true;

        int steps = 0;

        while(!q.empty())
        {
            int sz = q.size();

            while(sz--)
            {
                int i = q.front();
                q.pop();

                if(i == n - 1)
                    return steps;

                // left
                if(i > 0 && !seen[i - 1])
                {
                    seen[i - 1] = true;
                    q.push(i - 1);
                }

                // right
                if(i + 1 < n && !seen[i + 1])
                {
                    seen[i + 1] = true;
                    q.push(i + 1);
                }

                // factor jumps
                if(factors[nums[i]].size()==1)
                {
                    int p=nums[i];
                    if(edges.count(p))
                    {
                        for(int j : edges[p])
                        {
                            if(!seen[j])
                            {
                                seen[j] = true;
                                q.push(j);
                            }
                        }

                        edges.erase(p);
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};