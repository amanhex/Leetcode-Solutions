/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Constraints:
0 <= nums.length <= 105
-109 <= nums[i] <= 109
*/

// Using Sorting (T.C: O(nlogn) + O(n) && S.C: O(1))
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;
        sort(nums.begin(), nums.end());
        int currLong = 1, maxLong = 1;
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] == nums[i - 1] + 1)
                currLong++;
            else if (nums[i] == nums[i - 1])
                continue;
            else{
                maxLong = max(currLong, maxLong);
                currLong = 1;
            }
        }
        maxLong = max(currLong, maxLong);
        return maxLong;
    }
};

// Using Set (T.C: O(n) && S.C: O(n))
class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        int n = a.size();
        if (n == 0) return 0;
        int longest = 1;
        unordered_set<int> st;
        for (int i = 0; i < n; i++)
            st.insert(a[i]);
        for (auto it : st) {
            if (st.find(it - 1) == st.end()) {
                int cnt = 1;
                int x = it;
                while (st.find(x + 1) != st.end()) {
                    x = x + 1;
                    cnt = cnt + 1;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};