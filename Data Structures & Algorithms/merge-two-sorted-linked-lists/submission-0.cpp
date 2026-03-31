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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *list3 = nullptr;
        ListNode *ptr1 = list1;
        ListNode *ptr2 = list2;
        ListNode *ptr3 = nullptr;
        while(ptr1 != nullptr && ptr2 != nullptr) {
            if (list3 == nullptr) {
                list3 = new ListNode(min(ptr1->val, ptr2->val), nullptr);
                ptr3 = list3;
            } else {
                ptr3->next = new ListNode(min(ptr1->val, ptr2->val), nullptr);
                ptr3 = ptr3->next;

            }
            if (ptr1->val < ptr2->val) {
                ptr1 = ptr1->next;
            } else {
                ptr2 = ptr2->next;
            }
        }
        while (ptr1 != nullptr) {
            if (ptr3 == nullptr) {
                list3 = new ListNode(ptr1->val, nullptr);
                ptr3 = list3;
            } else {
                ptr3->next = new ListNode(ptr1->val, nullptr);
                ptr3 = ptr3->next;
            }
            ptr1 = ptr1->next;
        }
        while (ptr2 != nullptr) {
            if (ptr3 == nullptr) {
                list3 = new ListNode(ptr2->val, nullptr);
                ptr3 = list3;
            } else {
                ptr3->next = new ListNode(ptr2->val, nullptr);
                ptr3 = ptr3->next;
            }
            ptr2 = ptr2->next;
        }
        return list3;
    }
};
