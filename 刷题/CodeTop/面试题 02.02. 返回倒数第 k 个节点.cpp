/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        ListNode* slow = head, *fast = head;
        while(k-- && fast != NULL) {
            fast = fast->next;
        }
        while(fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow->val;
    }
};