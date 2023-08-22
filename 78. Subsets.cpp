/*
Given an integer array nums of unique elements, return all possible 
subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
Input: nums = [0]
Output: [[],[0]]

Constraints:
1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
*/

// Recursive Approach
class Solution {
public:
    void genSubsets(vector<int>& nums, vector<int>& currSubset, vector<vector<int>>& subsets, int index){
        if (index == nums.size()){
            subsets.push_back(currSubset);
            return;
        }
        currSubset.push_back(nums[index]);
        genSubsets(nums, currSubset, subsets, index + 1);
        currSubset.pop_back();
        genSubsets(nums, currSubset, subsets, index + 1);
        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> currSubset;
        vector<vector<int>> subsets;
        genSubsets(nums, currSubset, subsets, 0);
        return subsets;
    }
};


// Bit Mask Approach
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        int n = nums.size();
        int sub_cnt = 1 << n; // (1 left shift n means 2 ^ n)
        for (int mask = 0; mask < sub_cnt; mask++){
            vector<int> subset;
            for (int i = 0; i < n; i++){
                if ((mask & (1 << i)) != 0){
                    subset.push_back(nums[i]);
                }
            }
            subsets.push_back(subset);
        }
        return subsets;
    }
};
