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
    ListNode* reverseList(ListNode* head) {
        ListNode* ptr = head;
        stack<int> st;
        while(ptr != nullptr) {
            st.push(ptr->val);
            ptr = ptr->next;
        }
        ListNode *h = nullptr;
        ListNode *prev = nullptr;
        if (!st.empty()) {
            h = new ListNode(st.top(), nullptr);
            st.pop();
        }
        ptr = h;
        while(!st.empty()) {
            prev = ptr;
            ptr = new ListNode(st.top(), nullptr);
            prev->next = ptr;
            st.pop();
        }
        return h;
    }
};
