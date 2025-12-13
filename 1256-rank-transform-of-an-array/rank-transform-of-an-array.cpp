class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        vector<int> sortedarr=arr;
        unordered_map<int,int> hash;
        sort(arr.begin(),arr.end());
        int k=1;
        for (auto& num : arr)
        {
            if(hash.find(num)==hash.end())
            {
                hash[num]=k;
                k++;
            }
        }
        arr.clear();
        for (auto& a:sortedarr)
        {
            arr.push_back(hash[a]);
        }
        return arr;
    }
};