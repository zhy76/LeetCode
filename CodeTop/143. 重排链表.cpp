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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* next = cur;
        while(cur != nullptr) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

    ListNode* getMidNode(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* fast = head, *slow = head;
        while(fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow; //中间偏前一个
    }

    ListNode* mergeList(ListNode* l1, ListNode* l2) {
        ListNode* p = l1, *q = l2;
        while(p != l2 && q != nullptr) {
            ListNode* pt = p->next;
            ListNode* qt = q->next;
            p->next = q;
            q->next = pt;
            p = pt;
            q = qt;
        }
        return l1;
    }

    void reorderList(ListNode* head) {
        ListNode* mid = getMidNode(head);
        ListNode* l2 = mid->next;
        mid->next = nullptr;
        ListNode* l3 = reverseList(l2);
        mergeList(head, l3);
    }
};