/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.

Example 1:
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2:
Input: coins = [2], amount = 3
Output: -1

Example 3:
Input: coins = [1], amount = 0
Output: 0

Constraints:
    1 <= coins.length <= 12
    1 <= coins[i] <= 231 - 1
    0 <= amount <= 104
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> prev(amount + 1, 1e9);
        
        // Initializing the base case for the first coin
        for (int i = 0; i <= amount; i++){
            if (i % coins[0] == 0)
                prev[i] = i / coins[0];
        }

        // Fill the dp table
        for (int ind = 1; ind < coins.size(); ind++){
            vector<int> curr(amount + 1, 1e9);
            for (int t = 0; t <= amount; t++){
                int notTake = prev[t];
                int take = 1e9;
                if (coins[ind] <= t)
                    take = 1 + curr[t - coins[ind]];
                curr[t] = min(take, notTake);
            }
            prev = curr;
        }

        // Get the result from the dp table
        int res = prev[amount];
        return res >= 1e9 ? -1 : res;
    }
};
