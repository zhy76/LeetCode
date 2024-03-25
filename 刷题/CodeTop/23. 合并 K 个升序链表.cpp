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

// k路多并
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
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode* dummy = new ListNode(-1);
        ListNode* p = a, *q = b;
        ListNode* cur = dummy;
        while(p || q) {
            if(p == nullptr) {
                cur->next = q;
                break;
            } 
            if(q == nullptr) {
                cur->next = p;
                break;
            }
            if(p->val < q->val) {
                cur->next = p;
                p = p->next;
            } else {
                cur->next = q;
                q = q->next;
            }
            cur = cur->next;
        }
        return dummy->next;
    }

    ListNode* merge(vector<ListNode*>& lists, int l, int r) {
        if(l == r) return lists[l];
        if(l > r) return nullptr;
        int mid = l + (r- l) / 2;
        ListNode* left = merge(lists, l, mid);
        ListNode* right = merge(lists, mid + 1, r);
        return mergeTwoLists(left, right);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = merge(lists, 0, lists.size() - 1);
        return res;
    }
};