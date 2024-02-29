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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* merged = new ListNode();
        ListNode* cur = merged;
        ListNode* p = list1, *q = list2;
        while(p != nullptr && q != nullptr) {
            if(p->val < q->val) {
                cur->next = p;
                p = p->next;
            }
            else {
                cur->next = q;
                q = q->next;
            }
            cur = cur->next;
        } 
        if(p != nullptr) cur->next = p;
        if(q != nullptr) cur->next = q;
        return merged->next;
    }
};