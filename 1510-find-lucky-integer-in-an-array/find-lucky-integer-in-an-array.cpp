class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> hash;
        
        for(auto &a:arr)
            hash[a]++;
        int ans=-1;
        for(auto [key,value]:hash)
        {
            if(key==value)
            ans=max(ans,value);
        }
        return ans;
    }
};