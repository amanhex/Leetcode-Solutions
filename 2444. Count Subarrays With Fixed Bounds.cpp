/*
You are given an integer array nums and two integers minK and maxK.

A fixed-bound subarray of nums is a subarray that satisfies the following conditions:
    The minimum value in the subarray is equal to minK.
    The maximum value in the subarray is equal to maxK.

Return the number of fixed-bound subarrays.

A subarray is a contiguous part of an array.

Example 1:
Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
Output: 2
Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].

Example 2:
Input: nums = [1,1,1,1], minK = 1, maxK = 1
Output: 10
Explanation: Every subarray of nums is a fixed-bound subarray. There are 10 possible subarrays.

Constraints:
    2 <= nums.length <= 105
    1 <= nums[i], minK, maxK <= 106
*/

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int left = 0;
        long long ans = 0;
        int maxi = -1, mini = -1;
        for (int right = 0; right < nums.size(); right++){
            int x = nums[right];
            if (x < minK || x > maxK){
                left = right + 1;
                continue;
            }
            if (x == maxK) maxi = right;
            if (x == minK) mini = right;
            ans += max((min(maxi, mini) - left + 1), 0);
        }
        return ans;
    }
};
