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
    map<int, int> m;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (int i = 0; i < lists.size(); i++) {
            ListNode *ptr = lists[i];
            while (ptr != nullptr) {
                if (m.find(ptr->val) == m.end()) {
                    m.insert({ptr->val, 1});
                } else {
                    m.find(ptr->val)->second++;
                }
                ptr = ptr->next;
            }
        }
        ListNode* head = nullptr;
        ListNode* ptr = nullptr;
        while(!m.empty()) {
            int val = m.begin()->first;
            cout << val << endl;
            if (m.begin()->second < 2) {
                m.erase(m.begin());
            } else {
                m.begin()->second--;
            }
            if (head == nullptr) {
                ptr = new ListNode(val);
                head = ptr;
            } else {
                ptr->next = new ListNode(val);
                ptr = ptr->next;
            }
        }
        return head;
    }
};
