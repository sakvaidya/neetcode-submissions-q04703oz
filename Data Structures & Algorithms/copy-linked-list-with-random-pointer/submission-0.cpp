/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node *, Node *> m;
        Node* ptr = head;
        Node* head2 = nullptr;
        Node* ptr2 = head2;
        Node* temp = nullptr;
        while (ptr) {
            if (m.find(ptr) == m.end()) {
                temp = new Node(ptr->val);
                if (!ptr2) {
                    head2 = temp;
                    ptr2 = head2;
                } else {
                    ptr2->next = temp;
                    ptr2 = ptr2->next;
                }
                m.insert({ptr, ptr2});
            } else {
                if (!ptr2) {
                    head2 = temp;
                    ptr2 = head2;
                } else {
                    ptr2->next = m.find(ptr)->second;
                    ptr2 = ptr2->next;
                }
            }
            if (ptr->random) {
                if (m.find(ptr->random) == m.end()) {
                    temp = new Node((ptr->random)->val);
                    ptr2->random = temp;
                    m.insert({ptr->random, ptr2->random});
                } else {
                    ptr2->random = m.find(ptr->random)->second;
                }
            }
            ptr = ptr->next;
        }
        return head2;
    }
};
