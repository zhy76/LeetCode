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
    ListNode* trainingPlan(ListNode* head, int cnt) {
        ListNode* p1=head;
        ListNode* p2=head;
        for(int i=0;i<cnt;i++){
            p1=p1->next;
        }
        while(p1!=nullptr){
            p1=p1->next;
            p2=p2->next;
        }
        return p2;
    }
};