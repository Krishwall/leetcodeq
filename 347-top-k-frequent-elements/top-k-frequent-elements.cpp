class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;

        for(auto& a:nums)
        {
            map[a]++;
        }

        priority_queue<pair<int,int>> pq;

        for(auto it:map)
        {
            pq.push({it.second,it.first});
        }
        vector<int> ans;
        while(k!=0)
        {
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};