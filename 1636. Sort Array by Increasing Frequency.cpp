/*
Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.

Return the sorted array.

Example 1:
Input: nums = [1,1,2,2,2,3]
Output: [3,1,1,2,2,2]
Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.

Example 2:
Input: nums = [2,3,1,3,2]
Output: [1,3,3,2,2]
Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.

Example 3:
Input: nums = [-1,1,-6,4,5,-6,1,4,1]
Output: [5,-1,4,4,-6,-6,1,1,1]

Constraints:
    1 <= nums.length <= 100
    -100 <= nums[i] <= 100
*/

class Solution {
public:
    struct specialNum {
        int num;
        int freq;
    };

    static bool comp(const specialNum& s1, specialNum& s2){
        if (s1.freq == s2.freq) return s1.num > s2.num;
        return s1.freq < s2.freq;
    }

    vector<int> frequencySort(vector<int>& nums) {
        specialNum s[201] = {}; // Handle -ve numbers

        // Initialising specialNum array
        for (int i = 0; i < 201; i++){
            s[i].num = i - 100;
            s[i].freq = 0;
        }

        // Populating the specialNum array
        for (int num: nums){
            s[num + 100].freq++;
        }

        // Sort specialNum array based on custom comparator
        sort(s, s + 201, comp);

        // Adjusting nums
        int k = 0;
        for (int i = 0; i < 201; i++){
            if (s[i].freq > 0){
                for (int j = 0; j < s[i].freq; j++)
                    nums[k++] = s[i].num;
            }
        }

        return nums;
    }
};
