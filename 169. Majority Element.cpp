/*
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Example 1:
Input: nums = [3,2,3]
Output: 3

Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2

Constraints:
n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109

Follow-up: Could you solve the problem in linear time and in O(1) space?
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counter;
        for (int num : nums) {
            if (++counter[num] > nums.size() / 2) {
                return num;
            }
        }
        return 0;
    }
};

// Optimal Approach
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element, count = 0;
        for (int i = 0; i < nums.size(); i++){
            if (count == 0){
                element = nums[i];
                count++;
            }
            else if (nums[i] == element)
                count++;
            else
                count--;
        }
        return element;
    }
};