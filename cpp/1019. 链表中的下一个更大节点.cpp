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
    vector<int> nextLargerNodes(ListNode* head) {
        stack<pair<int,int> > st;
        vector<int> ans;
        ListNode* p=head;
        int ind=-1;
        while(p!=nullptr){
            ++ind;
            ans.push_back(0);
            while(!st.empty() && st.top().first<p->val){
                ans[st.top().second]=p->val;
                st.pop();
            }
            st.push({p->val,ind});
            p=p->next;
        }
        return ans;
    }
};