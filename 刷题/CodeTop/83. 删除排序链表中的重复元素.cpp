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
        if(head == nullptr) return head;
        ListNode* p = head;
        ListNode* nxt = head->next;
        int val = head->val;
        while(nxt != nullptr && p != nullptr) {
            if(val == nxt->val) {
                nxt = nxt->next;
            } else {
                p->next = nxt;
                p = p->next;
                nxt = nxt->next;
                val = p->val;
            }
        }
        if(nxt == nullptr) p->next = nullptr;
        return head;
    }
};