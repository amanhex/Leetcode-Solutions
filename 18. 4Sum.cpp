/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

Example 1:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:
Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]

Constraints:
1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> setQuad;
        for (int i = 0; i < nums.size(); i++){
            for (int j = i + 1; j < nums.size(); j++){
                set<long long> st;
                for (int k = j + 1; k < nums.size(); k++){
                    long long sum = (long long)nums[i] + nums[j] + nums[k];
                    long long search = (long long)target - sum;
                    if (st.find(search) != st.end()){
                        vector<int> temp = {nums[i], nums[j], nums[k], (int)search};
                        sort(temp.begin(), temp.end());
                        setQuad.insert(temp);
                    }
                    st.insert(nums[k]);
                }
            }
        }
        vector<vector<int>> ans(setQuad.begin(), setQuad.end());
        return ans;
    }
};

// Optimal Solution (Using 2 Pointers)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i++){
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < nums.size(); j++){
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int k = j + 1, l = nums.size() - 1;
                while (k < l){
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if (sum == target){
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        while (k < l && nums[k] == nums[k + 1])
                            k++;
                        while (k < l && nums[l] == nums[l - 1])
                            l--;
                        k++, l--;
                    }
                    else if (sum > target)
                        l--;
                    else
                        k++;
                }
            }
        }
        return ans;
    }
};
