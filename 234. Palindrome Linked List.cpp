/*
Given the head of a singly linked list, return true if it is a 
palindrome or false otherwise.

Example 1:
Input: head = [1,2,2,1]
Output: true

Example 2:
Input: head = [1,2]
Output: false

Constraints:
The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9

Follow up: Could you do it in O(n) time and O(1) space?
*/

// Traversing to mid of LL and saving values in array simultaneously and comparing array to LL for second half
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
    bool isPalindrome(ListNode* head) {
        if (!head || !(head -> next))
            return true;
        vector<int> firstHalf;
        ListNode* slow = head, *fast = head;
        while (fast && (fast -> next)){
            firstHalf.push_back(slow -> val);
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        if (fast)
            slow = slow -> next;
        int i = 0;
        while (slow){
            if (slow -> val != firstHalf[firstHalf.size() - i - 1])
                return false;
            i++;
            slow = slow -> next;
        }
        return true;
    }
};

// Optimized
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head, *prev, *temp;
        while (fast && fast->next)
            slow = slow->next, fast = fast->next->next;
        prev = slow, slow = slow->next, prev->next = NULL;
        while (slow)
            temp = slow->next, slow->next = prev, prev = slow, slow = temp;
        fast = head, slow = prev;
        while (slow)
            if (fast->val != slow->val) return false;
            else fast = fast->next, slow = slow->next;
        return true;
    }
};