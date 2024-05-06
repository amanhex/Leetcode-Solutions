/*
You are given the head of a linked list.
Remove every node which has a node with a greater value anywhere to the right side of it.
Return the head of the modified linked list.

Example 1:
Input: head = [5,2,13,3,8]
Output: [13,8]
Explanation: The nodes that should be removed are 5, 2 and 3.
- Node 13 is to the right of node 5.
- Node 13 is to the right of node 2.
- Node 8 is to the right of node 3.

Example 2:
Input: head = [1,1,1,1]
Output: [1,1,1,1]
Explanation: Every node has value 1, so no nodes are removed.

Constraints:
    The number of the nodes in the given list is in the range [1, 105].
    1 <= Node.val <= 105
*/

/**
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
    ListNode* removeNodes(ListNode* head) {
        if (!head || !head -> next)
            return head;
        ListNode* node = removeNodes(head -> next);

        if (node -> val > head -> val)
            return node;
        head -> next = node;
        return head;
    }
};


// Using Stack
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
    ListNode* removeNodes(ListNode* head) {
        stack<int> st;
        ListNode* curr = head;
        while (curr){
            while (!st.empty() && st.top() < curr -> val)
                st.pop();
            st.push(curr -> val);
            curr = curr -> next;
        }
        ListNode* newHead = nullptr;
        while (!st.empty()){
            ListNode* newNode = new ListNode(st.top());
            newNode -> next = newHead;
            newHead = newNode;
            st.pop();
        }
        return newHead;
    }
};
