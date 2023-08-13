/*
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Example 2:
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]

Constraints:
The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000

Follow-up: Can you solve the problem in O(1) extra memory space?
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
    int getLength(ListNode* head, int k){
        if (!head)
            return 0;
        int length = 0;
        ListNode* temp = head;
        while (temp && length < k){
            length++;
            temp = temp -> next;
        }
        return length;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head -> next)
            return head;
        ListNode* prev = nullptr, *curr = head;
        int check = getLength(curr, k);
        if (check < k)
            return curr;
        int count = 0;
        while (curr && count < k){
            ListNode* temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
            count++;
        }
        head -> next = reverseKGroup(curr, k);
        return prev;
    }
};
