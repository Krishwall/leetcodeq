class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
         int aliceTotal = 0;
        int bobTotal = 0;
        for (int candies : aliceSizes) aliceTotal += candies;
        for (int candies : bobSizes) bobTotal += candies;

        unordered_set<int> targets;
        for (int i = 0, m = aliceSizes.size(); i < m; i++)
            targets.insert((bobTotal - aliceTotal + 2 * aliceSizes[i]) / 2);

        for (int j = 0, n = bobSizes.size(); j < n; j++)
            if (targets.find(bobSizes[j])!=targets.end())
        return vector<int> {(aliceTotal+2*bobSizes[j]-bobTotal)/2,bobSizes[j]};
    return {0};
    }
};