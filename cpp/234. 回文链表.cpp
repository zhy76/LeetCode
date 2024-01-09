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
    ListNode* reverse(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* last = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* right = reverse(slow);
        ListNode* left = head;
        while(right != nullptr) {
            if(left->val != right->val) return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }
};