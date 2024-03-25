/*
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra space.

Example 1:
Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]

Example 2:
Input: nums = [1,1,2]
Output: [1]

Example 3:
Input: nums = [1]
Output: []

Constraints:
    n == nums.length
    1 <= n <= 105
    1 <= nums[i] <= n
    Each element in nums appears once or twice.
*/

// Using Hashmap
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
            map[nums[i]]++;
        vector<int> ans;
        for (auto i = map.begin(); i != map.end(); i++){
            if (i -> second == 2)
                ans.push_back(i -> first);
        }
        return ans;
    }
};

// Using sorting
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] == nums[i - 1])
                ans.push_back(nums[i]);
        }
        return ans;
    }
};

// Using ranges
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            int x = abs(nums[i]);
            if (nums[x - 1] < 0)
                ans.push_back(x);
            nums[x - 1] *= -1;
        }
        return ans;
    }
};
