class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;

        // Step 1: Frequency count
        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Buckets (index = frequency)
        int n = nums.size();
        vector<vector<int>> bucket(n + 1);

        for (auto &it : freq) {
            bucket[it.second].push_back(it.first);
        }

        // Step 3: Collect top k frequent elements
        vector<int> ans;
        for (int i = n; i >= 0 && k > 0; i--) {
            for (int num : bucket[i]) {
                ans.push_back(num);
                if (--k == 0) break;
            }
        }

        return ans;
    }
};
