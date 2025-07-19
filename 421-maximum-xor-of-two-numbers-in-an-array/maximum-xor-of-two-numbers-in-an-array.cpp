class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxXOR = 0, mask = 0;
        for (int i = 31; i >= 0; --i) {
            mask |= (1 << i);
            unordered_set<int> prefixes;
            for (int num : nums) {
                prefixes.insert(num & mask);
            }

            int candidate = maxXOR | (1 << i);
            for (int prefix : prefixes) {
                if (prefixes.count(candidate ^ prefix)) {
                    maxXOR = candidate;
                    break;
                }
            }
        }
        return maxXOR;
    }
};
