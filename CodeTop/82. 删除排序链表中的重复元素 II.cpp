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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* next = head->next;
        while(next != nullptr && next->val == head->val) {
            next = next->next;
        }
        if(next != head->next) return deleteDuplicates(next);
        head->next = deleteDuplicates(head->next);
        return head;
    }
};