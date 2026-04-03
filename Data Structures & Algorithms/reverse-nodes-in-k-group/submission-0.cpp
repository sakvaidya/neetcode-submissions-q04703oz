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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ptr = head;
        ListNode* prev = nullptr;
        ListNode* tail;
        int count = 0;
        while (ptr) {
            ptr = ptr->next;
            count++;
        }
        ptr = head;
        cout << count << endl;
        if (count < k) {
            return head;
        }
        
        ListNode* next;
        tail = ptr;
        for (int i = 0; i < k; i++) {
            cout << ptr->val << endl;
            next = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = next;
        }

        if (ptr) {
            tail->next = reverseKGroup(ptr, k);
        }
        return prev;
    }
};
