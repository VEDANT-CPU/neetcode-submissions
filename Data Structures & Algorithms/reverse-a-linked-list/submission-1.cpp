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
       ListNode* it=head;
       ListNode* n=it;
       ListNode* prev=nullptr;
       while(it != nullptr) {
        if(n != nullptr) n = n->next;
        it->next = prev;
        prev = it;
        it = n;
        
       }
       return prev;
    }
};
