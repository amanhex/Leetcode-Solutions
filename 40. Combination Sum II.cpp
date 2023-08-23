/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

Example 2:
Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]

Constraints:
1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
*/

class Solution {
public:
    void backTrack(vector<int>& nums, vector<vector<int>>& res, vector<int>& subset, int remain, int index){
        if (remain == 0){
            res.push_back(subset);
            return;
        }
        if (remain < 0)
            return;
        for (int i = index; i < nums.size(); i++){
            if (i != index && nums[i] == nums[i - 1])
                continue;
            subset.push_back(nums[i]);
            backTrack(nums, res, subset, remain - nums[i], i + 1);
            subset.pop_back();
        }
        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        sort(candidates.begin(), candidates.end());
        backTrack(candidates, res, subset, target, 0);
        return res;
    }
};
