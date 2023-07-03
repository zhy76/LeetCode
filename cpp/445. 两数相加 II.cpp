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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3=nullptr;
        stack<int> st1, st2;
        while(l1!=nullptr){
            st1.push(l1->val);
            l1=l1->next;
        }
        while(l2!=nullptr){
            st2.push(l2->val);
            l2=l2->next;
        }
        int carry=0;
        while(!st1.empty()||!st2.empty()||carry!=0){
            int a=st1.empty()?0:st1.top();
            int b=st2.empty()?0:st2.top();
            if(!st1.empty()) st1.pop();
            if(!st2.empty()) st2.pop();
            int cur=a+b+carry;
            carry=cur/10;
            cur%=10;
            auto curnode=new ListNode(cur);
            curnode->next=l3;
            l3=curnode;
        }
        return l3;
    }   
};