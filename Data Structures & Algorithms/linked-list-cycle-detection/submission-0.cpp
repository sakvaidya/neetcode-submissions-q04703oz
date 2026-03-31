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
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode *> s;
        ListNode *ptr = head;
        if (!head) {
            return false;
        }
        s.insert(ptr);
        while(ptr->next != nullptr && s.find(ptr->next) == s.end()) {
            s.insert(ptr->next);
            ptr = ptr->next;
        } 
        if (ptr->next == nullptr) {
            return false;
        } else {
            return true;
        }
    }
};
