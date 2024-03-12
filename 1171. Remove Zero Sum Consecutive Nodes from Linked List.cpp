/*
Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.

After doing so, return the head of the final linked list.  You may return any such answer.

(Note that in the examples below, all sequences are serializations of ListNode objects.)

Example 1:
Input: head = [1,2,-3,3,1]
Output: [3,1]
Note: The answer [1,2,1] would also be accepted.

Example 2:
Input: head = [1,2,3,-3,4]
Output: [1,2,4]

Example 3:
Input: head = [1,2,3,-3,-2]
Output: [1]

Constraints:
    The given linked list will contain between 1 and 1000 nodes.
    Each node in the linked list has -1000 <= node.val <= 1000.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        int prefixSum = 0;
        unordered_map<int, ListNode*> prefixSums;
        prefixSums[0] = dummy;
        ListNode* current = head;

        while (current){
            prefixSum += current -> val;
            if (prefixSums.count(prefixSum)){
                ListNode* toDelete = prefixSums[prefixSum] -> next;
                int tempSum = prefixSum + toDelete -> val;
                while (toDelete != current){
                    prefixSums.erase(tempSum);
                    toDelete = toDelete -> next;
                    tempSum += toDelete -> val;
                }
                prefixSums[prefixSum] -> next = current -> next;
            }
            else
                prefixSums[prefixSum] = current;
            current = current -> next;
        }
        
        return dummy -> next;
    }
};
