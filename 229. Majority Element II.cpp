/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Example 1:
Input: nums = [3,2,3]
Output: [3]

Example 2:
Input: nums = [1]
Output: [1]

Example 3:
Input: nums = [1,2]
Output: [1,2]

Constraints:
1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109

Follow up: Could you solve the problem in linear time and in O(1) space?
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int minCount = (int)(n / 3) + 1;
        unordered_map<int, int> map;
        vector<int> res;
        for (int i = 0; i < n; i++){
            map[nums[i]]++;
            if (map[nums[i]] == minCount)
                res.push_back(nums[i]);
            if (res.size() == 2)
                break;
        }
        return res;
    }
};

// Moore's Algorithm (Optimal)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2 = 0, element1, element2;
        for (int i = 0; i < nums.size(); i++){
            if (count1 == 0 && element2 != nums[i]){
                element1 = nums[i];
                count1++;
            }
            else if (count2 == 0 && element1 != nums[i]){
                element2 = nums[i];
                count2++;
            }
            else if (nums[i] == element1)
                count1++;
            else if (nums[i] == element2)
                count2++;
            else
                count1--, count2--;
        }
        count1 = 0, count2 = 0;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == element1)
                count1++;
            if (nums[i] == element2)
                count2++;
        }
        int minCount = (int)(nums.size() / 3) + 1;
        if (count1 >= minCount)
            res.push_back(element1);
        if (count2 >= minCount)
            res.push_back(element2);
        return res;
    }
};