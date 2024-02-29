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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* ans=new ListNode(-1);
        ListNode* p=ans;
        ListNode* cur=head;
        while(cur != nullptr) {
            if(cur->next == nullptr) {
                break;
            }
            ListNode* nt=cur->next;
            ListNode* tmp=nt->next;
            p->next=nt;
            nt->next=cur;
            cur->next=nullptr;
            p=cur;
            cur=tmp;
        }
        p->next=cur;
        return ans->next;
    }
};