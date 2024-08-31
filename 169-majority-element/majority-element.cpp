
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int* arr;
        unordered_map<int,int> m;
        for(auto& a :nums)
        {
            m[a]++;

        }
        for (auto& b:m)
        if (b.second>nums.size()/2)
            return b.first;
    return 1;
    }
};