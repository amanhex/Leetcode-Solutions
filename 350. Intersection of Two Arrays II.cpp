/*
Given two integer arrays nums1 and nums2, return an array of their intersection.
Each element in the result must appear as many times as it shows in both arrays
and you may return the result in any order.

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]

Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.

Constraints:
1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000

Follow up:
What if the given array is already sorted? How would you optimize your
algorithm? What if nums1's size is small compared to nums2's size? Which
algorithm is better? What if elements of nums2 are stored on disk, and the
memory is limited such that you cannot load all elements into the memory at
once?
*/

// Using HashMap
class Solution {
public:
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();
    unordered_map<int, int> map;
    vector<int> ans;
    if (n1 < n2) {
      for (int i = 0; i < n1; i++)
        map[nums1[i]]++;
      for (int i = 0; i < n2; i++) {
        if (map.count(nums2[i]) != 0) {
          map[nums2[i]]--;
          ans.push_back(nums2[i]);
          if (map[nums2[i]] == 0) {
            map.erase(nums2[i]);
          }
        }
      }
    } else {
      for (int i = 0; i < n2; i++)
        map[nums2[i]]++;
      for (int i = 0; i < n1; i++) {
        if (map.count(nums1[i]) != 0) {
          map[nums1[i]]--;
          ans.push_back(nums1[i]);
          if (map[nums1[i]] == 0) {
            map.erase(nums1[i]);
          }
        }
      }
    }
    return ans;
  }
};