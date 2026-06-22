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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* nodeptr = head;
        int ll_size=0;
        while(nodeptr != nullptr) {
            ll_size++;
            nodeptr = nodeptr->next;
        }
        nodeptr=head;
        ListNode* prev = nodeptr;
        int dist=ll_size-n;
        while(dist > 0) {
            prev = nodeptr;
            nodeptr = nodeptr->next;
            dist--;
        }
        ListNode* new_head = head;
        if(nodeptr == head) {
            new_head = head->next;
        }
        prev->next = nodeptr->next;
        nodeptr->next = nullptr;
        
        return new_head;
    }
};
