/*
Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

Example 1:
Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.

Example 2:
Input: nums = [-1,0]
Output: [-1,0]

Example 3:
Input: nums = [0,1]
Output: [1,0]

Constraints:
    2 <= nums.length <= 3 * 104
    -231 <= nums[i] <= 231 - 1
    Each integer in nums will appear twice, only two integers will appear once.
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorr = 0;
        for (int i : nums)
            xorr ^= i;
        
        int diff_bit = 1;
        while (!(xorr & diff_bit)){
            diff_bit = diff_bit << 1;
        }

        int a = 0, b = 0;
        for (auto i : nums){
            if (diff_bit & i)
                a = a ^ i;
            else
                b = b ^ i;
        }

        return {a, b};
    }
};
