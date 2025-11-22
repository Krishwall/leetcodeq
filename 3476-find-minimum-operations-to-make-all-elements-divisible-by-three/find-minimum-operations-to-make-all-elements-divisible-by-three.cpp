class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count =0;
        for(auto &a:nums)
            count+=min(a%3,3-(a%3));
    return count;

    }
};