// 法一：自顶向下
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
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next ==nullptr) return head;
        ListNode* slow=head, *fast=head,*mid=head;
        while(fast!=nullptr && fast->next!=nullptr){
            mid=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        mid->next=nullptr;

        ListNode* l=sortList(head);
        ListNode* r=sortList(slow);

        return merge(l,r);
    }

    ListNode* merge(ListNode* head1, ListNode* head2){
        ListNode* dummy = new ListNode(0);
        ListNode* p1=head1, *p2=head2,*p3=dummy;
        while(p1 != nullptr && p2 !=nullptr) {
            if(p1->val <= p2->val){
                p3->next=p1;
                p1=p1->next;
            } else {
                p3->next=p2;
                p2=p2->next;
            }
            p3=p3->next;
        }
        if(p1!=nullptr){
            p3->next = p1;
        } else if(p2!=nullptr) {
            p3->next = p2;
        }
        return dummy->next;
    }
    
};

// 法2：自底向上
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
    ListNode* sortList(ListNode* head) {
        if(head == nullptr) return head;
        int length=0;
        ListNode* node= head;
        while(node != nullptr){
            length++;
            node=node->next;
        }
        ListNode* dummyHead = new ListNode(0,head);
        for(int subLength = 1; subLength <length; subLength <<=1) {
            ListNode* prev = dummyHead, *curr = dummyHead->next;
            while(curr!=nullptr){
                ListNode* head1 = curr;
                for(int i=1;i<subLength && curr->next!=nullptr;i++){
                    curr=curr->next;
                }
                ListNode* head2=curr->next;
                curr->next=nullptr;
                curr=head2;
                for(int i=1;i<subLength && curr!=nullptr && curr->next != nullptr;i++){
                    curr = curr->next;
                }
                ListNode* next=nullptr;
                if(curr !=nullptr) {
                    next=curr->next;
                    curr->next=nullptr;
                }
                ListNode* merged = merge(head1,head2);
                prev->next = merged;
                while(prev->next!=nullptr){
                    prev=prev->next;
                }
                curr=next;
            }
        }
        return dummyHead->next;
    }

    ListNode* merge(ListNode* head1, ListNode* head2){
        ListNode* dummy = new ListNode(0);
        ListNode* p1=head1, *p2=head2,*p3=dummy;
        while(p1 != nullptr && p2 !=nullptr) {
            if(p1->val <= p2->val){
                p3->next=p1;
                p1=p1->next;
            } else {
                p3->next=p2;
                p2=p2->next;
            }
            p3=p3->next;
        }
        if(p1!=nullptr){
            p3->next = p1;
        } else if(p2!=nullptr) {
            p3->next = p2;
        }
        return dummy->next;
    }
    
};