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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pre=head;
        int cnt=0;
        while(pre!=nullptr){
            cnt++;
            pre=pre->next;
        }
        cout<<cnt<<endl;
        ListNode* tmp=new ListNode(0,head);
        ListNode* cur=tmp;
         for (int i = 1; i < cnt - n + 1; ++i) {
            cur = cur->next;
        }
        cur->next=cur->next->next;
        ListNode* ans=tmp->next;
        delete(tmp);
        return ans;
    }
};