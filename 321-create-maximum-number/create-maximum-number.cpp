#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> maxi;
        int start = max(0, k - m);
        int end = min(k, n);
        for (int i = start; i <= end; i++) {
            vector<int> sub1 = biggestElementsArray(nums1, i);
            vector<int> sub2 = biggestElementsArray(nums2, k - i);
            vector<int> tmp = merge(sub1, sub2);
            if (maxi.empty() || tmp > maxi) {
                maxi = tmp;
            }
        }
        return maxi;
    }

private:
    vector<int> biggestElementsArray(vector<int>& nums, int k) {
        int drop = nums.size()-k;
        vector<int> res;
        for (int num : nums) {
            while (drop > 0 && !res.empty() && res.back() < num) {
                res.pop_back();
                drop--;
            }
            res.push_back(num);
        }
        res.resize(k);
        return res;
    }

    vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int i = 0, j = 0;
        while (i < nums1.size() || j < nums2.size()) {
            if (greater(nums1, i, nums2, j)) {
                res.push_back(nums1[i++]);
            } else {
                res.push_back(nums2[j++]);
            }
        }
        return res;
    }

    bool greater(vector<int>& nums1, int i, vector<int>& nums2, int j) {
        while (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]) {
            i++;
            j++;
        }
        if (j == nums2.size()) return true;
        if (i == nums1.size()) return false;
        return nums1[i] > nums2[j];
    }
};