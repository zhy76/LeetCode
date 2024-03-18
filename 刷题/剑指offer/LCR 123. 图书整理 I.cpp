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
    vector<int> reverseBookList(ListNode* head) {
        vector<int> res;
        ListNode* pre = nullptr, *cur = head, *nxt = cur;
        while(cur != nullptr) {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        } 
        ListNode* p = pre;
        while(p != nullptr) {
            res.push_back(p->val);
            p = p->next;
        }
        return res;
    }
};