class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int lidx = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == nums[lidx]) continue;

            if (nums[i] - nums[lidx] == 1) {
                ans = max(ans, i - lidx+1);
            } else if (nums[i] - nums[lidx] > 1) {
                
                while (lidx < i && nums[i] - nums[lidx] > 1) {
                    ++lidx;
                }
                if (nums[i] - nums[lidx] == 1) {
                    ans = max(ans, i - lidx + 1);
                }
            }
        }

        return ans;
    }
};
