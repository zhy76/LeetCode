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
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* newhead = slow->next;
        slow->next = nullptr;
        return newhead;
    }
    ListNode* reverse(ListNode* head) {
        ListNode* pre = nullptr, *cur = head, *nxt = head;
        while(cur != nullptr) {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
    void merge(ListNode* a, ListNode* b) {
        ListNode* p = a, *q = b;
        while(p != nullptr && q != nullptr) {
            ListNode* pn = p->next, *qn = q->next;
            p->next = q;
            q->next = pn;
            p = pn;
            q = qn;
        }
        // return a;
    }
    void reorderList(ListNode* head) {
        ListNode* mid = getMid(head);
        ListNode* b = reverse(mid);
        merge(head, b);
    }
};