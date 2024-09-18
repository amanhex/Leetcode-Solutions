/*
Given a list of non-negative integers nums, arrange them such that they form the
largest number and return it.

Since the result may be very large, so you need to return a string instead of an
integer.

Example 1:
Input: nums = [10,2]
Output: "210"

Example 2:
Input: nums = [3,30,34,5,9]
Output: "9534330"

Constraints:
    1 <= nums.length <= 100
    0 <= nums[i] <= 109
*/

class Solution {
  static bool comparator(int a, int b) {
    string na = to_string(a);
    string nb = to_string(b);
    if ((na + nb) > (nb + na))
      return true;
    return false;
  }

public:
  string largestNumber(vector<int> &nums) {
    sort(nums.begin(), nums.end(), comparator);
    if (nums[0] == 0)
      return "0";
    string ans = "";
    for (int num : nums)
      ans += to_string(num);
    return ans;
  }
};
