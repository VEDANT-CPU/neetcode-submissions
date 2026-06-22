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
        Node* new_list;
        unordered_map<Node*, Node*>Nodemp;
        if(head != nullptr) {
            new_list = new Node(head->val);
            //new_list->next = head->next;
            //new_list->random = head->random;
            Nodemp[head] = new_list;
        }else {
            new_list = nullptr;
        }
        Node* iter = head;
        Node* temp = new_list;
        while(iter != nullptr) {
            if(iter==head && head != nullptr) {
                iter = iter->next;
            }else {
                Node* new_node = new Node(iter->val);
                temp->next = new_node;
                Nodemp[iter] = new_node;
                temp = temp->next;
                iter = iter->next;
            }
        }
        iter = head;
        temp = new_list;
        while(iter != nullptr) {
            if(iter->random != nullptr) temp->random = Nodemp[iter->random];
            else temp->random = nullptr;
            temp = temp->next;
            iter = iter->next;
        }
        return new_list;
    }
};
