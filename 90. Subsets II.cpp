/*
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

Example 2:
Input: nums = [0]
Output: [[],[0]]

Constraints:
1 <= nums.length <= 10
-10 <= nums[i] <= 10
*/

// Recursive Approach
class Solution {
public:
    void genSubsets(vector<int>& nums, vector<int>& currSubset, vector<vector<int>>& subsets, int index){
        subsets.push_back(currSubset);
        for (int i = index; i < nums.size(); i++){
            if (i != index && nums[i] == nums[i - 1])
                continue;
            currSubset.push_back(nums[i]);
            genSubsets(nums, currSubset, subsets, i + 1);
            currSubset.pop_back();
        }
        return;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> currSubset;
        vector<vector<int>> subsets;
        genSubsets(nums, currSubset, subsets, 0);
        return subsets;
    }
};

// Bit Masking Approach
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int sub_cnt = 1 << n;
        set<vector<int>> st;
        for (int mask = 0; mask < sub_cnt; mask++){
            vector<int> subsets;
            for (int i = 0; i < n; i++){
                if (mask & (1 << i))
                    subsets.push_back(nums[i]);
            }
            st.insert(subsets);
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};
