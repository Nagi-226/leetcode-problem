#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> maxNum(k, 0);
        for (int i = max(0, k - (int)nums2.size()); i <= min(k, (int)nums1.size()); ++i) {
            vector<int> candidate = merge(maxArray(nums1, i), maxArray(nums2, k - i), k);
            if (greater(candidate, 0, maxNum, 0)) {
                maxNum = candidate;
            }
        }
        return maxNum;
    }

private:
    vector<int> maxArray(vector<int>& nums, int k) {
        vector<int> result(k, 0);
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            while (j > 0 && nums[i] > result[j - 1] && nums.size() - i + j > k) {
                --j;
            }
            if (j < k) {
                result[j++] = nums[i];
            }
        }
        return result;
    }

    vector<int> merge(vector<int> nums1, vector<int> nums2, int k) {
        vector<int> result(k, 0);
        int i = 0, j = 0, r = 0;
        while (r < k) {
            if (greater(nums1, i, nums2, j)) {
                result[r++] = nums1[i++];
            } else {
                result[r++] = nums2[j++];
            }
        }
        return result;
    }

    bool greater(vector<int>& nums1, int i, vector<int>& nums2, int j) {
        while (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]) {
            ++i;
            ++j;
        }
        return j == nums2.size() || (i < nums1.size() && nums1[i] > nums2[j]);
    }
};

