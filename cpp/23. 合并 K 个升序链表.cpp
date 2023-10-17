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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, function<bool(ListNode*, ListNode*)> > qu([](ListNode* a, ListNode* b){
            return a->val > b->val;
        });
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=nullptr){
                qu.push(lists[i]);
            }
        }
        ListNode* dummy=new ListNode(-1);
        ListNode* p=dummy;
        while(!qu.empty()){
            ListNode* t=qu.top();
            qu.pop();
            p->next=t;
            if(t->next!=nullptr){
                qu.push(t->next);
            }
            p=p->next;
        }
        return dummy->next;
    }
};