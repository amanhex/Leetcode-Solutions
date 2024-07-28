/*
You are a professional robber planning to rob houses along a street. Each house
has a certain amount of money stashed, the only constraint stopping you from
robbing each of them is that adjacent houses have security systems connected and
it will automatically contact the police if two adjacent houses were broken into
on the same night. Given an integer array nums representing the amount of money
of each house, return the maximum amount of money you can rob tonight without
alerting the police.

Example 1:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 2:
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5
(money = 1). Total amount you can rob = 2 + 9 + 1 = 12.

Constraints:
1 <= nums.length <= 100
0 <= nums[i] <= 400
*/

class Solution {
public:
  int rob(vector<int> &nums, int prev, int curr, int i) {
    if (i >= nums.size())
      return curr;
    int temp = max(prev + nums[i], curr);
    return rob(nums, curr, temp, i + 1);
  }

  int rob(vector<int> &nums) {
    if (nums.size() == 0)
      return 0;
    return rob(nums, 0, 0, 0);
  }
};

// Using Memoization
class Solution {
public:
  int f(vector<int> &nums, vector<int> &dp, int pos) {
    if (pos == 0)
      return nums[0];
    if (pos < 0)
      return 0;

    if (dp[pos] != -1)
      return dp[pos];

    int take = nums[pos] + f(nums, dp, pos - 2);
    int notTake = f(nums, dp, pos - 1);
    return dp[pos] = max(take, notTake);
  }
  int rob(vector<int> &nums) {
    vector<int> dp(nums.size(), -1);
    return f(nums, dp, nums.size() - 1);
  }
};

// Using Tabulation
class Solution {
public:
  int rob(vector<int> &nums) {
    vector<int> dp(nums.size(), -1);
    dp[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      int take = nums[i];
      if (i > 1)
        take += dp[i - 2];
      int notTake = dp[i - 1];
      dp[i] = max(take, notTake);
    }
    return dp[nums.size() - 1];
  }
};

// Optimal Method (Space Optimization with Dp)
class Solution {
public:
  int rob(vector<int> &nums) {
    int prev = nums[0], prev2 = 0;
    for (int i = 1; i < nums.size(); i++) {
      int take = nums[i];
      if (i > 1)
        take += prev2;
      int notTake = prev;
      int curr = max(take, notTake);
      prev2 = prev;
      prev = curr;
    }
    return prev;
  }
};
