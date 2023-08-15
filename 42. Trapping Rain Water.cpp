/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:
Input: height = [4,2,0,3,2,5]
Output: 9

Constraints:
n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0, left = 0, right = height.size() - 1;
        int maxLeft = 0, maxRight = 0;
        while (left <= right){
            if (height[left] <= maxRight){
                if (height[left] < maxLeft)
                    res += maxLeft - height[left];
                else
                    maxLeft = max(maxLeft, height[left]);
                left++;
            }
            else{
                if (height[right] < maxRight)
                    res += maxRight - height[right];
                else
                    maxRight = max(maxRight, height[right]);
                right--;
            }
        }
        return res;
    }
};
