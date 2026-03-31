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
        int carry = 0;
        int sum = 0;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* out = nullptr;
        ListNode* p3 = out;
        ListNode* temp;
        while (p1 && p2) {
            sum = p1->val + p2->val + carry;
            temp = new ListNode(sum%10);
            carry = sum/10;
            if (!p3) {
                out = temp;
                p3 = out;
            } else {
                p3->next = temp;
                p3 = p3->next;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        while (p1) {
            if (carry == 0) {
                temp = new ListNode(p1->val);
            } else {
                temp = new ListNode((p1->val+carry)%10);
                carry = (p1->val + carry)/10;
            }
            if (!p3) {
                out = temp;
                p3 = out;
            } else {
                p3->next = temp;
                p3 = p3->next;
            }
            p1 = p1->next;
        }
        while (p2) {
            if (carry == 0) {
                temp = new ListNode(p2->val);
            } else {
                temp = new ListNode((p2->val+carry)%10);
                carry = (p2->val + carry)/10;
            }
            if (!p3) {
                out = temp;
                p3 = out;
            } else {
                p3->next = temp;
                p3 = p3->next;
            }
            p2 = p2->next;
        }
        if (carry > 0) {
            temp = new ListNode(carry);
            p3->next = temp;
        }
        return out;
    }
};
