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
    struct cmp {
        bool operator ()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> qu;
        for(auto list: lists) {
            if(list != nullptr) qu.push(list);
        }
        ListNode* dummy = new ListNode();
        ListNode* p = dummy;
        while(!qu.empty()){
            ListNode* cur = qu.top();
            qu.pop();
            p->next = cur;
            if(cur->next != nullptr) qu.push(cur->next);
            p = p->next;
        }
        return dummy->next;
    }
};