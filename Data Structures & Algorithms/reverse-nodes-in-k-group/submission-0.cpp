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
    ListNode* reverseList(ListNode*& start, ListNode*& end) {
        ListNode* prev=nullptr;
        ListNode* curr = start;
        ListNode* forward = start->next;
        while(prev != end) {
            curr->next = prev;
            prev = curr;
            curr = forward;
            if(forward!=nullptr) forward = forward->next;
        }
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int ll_size=0;
        ListNode* temp = head;
        while(temp != nullptr) {
            ll_size++;
            temp = temp->next;
        }
        int numGroups = ll_size/k;
        if(numGroups==0) return head;
        
        ListNode* l = head;
        ListNode* lk = head;
        ListNode* r=head;
        ListNode* t1 = nullptr;
        for(int i=1; i<=numGroups; i++) {
            int cnt=k;
            l=r;
            lk=r;
            while(cnt--) {
                lk = r;
                r = r->next;
            }
            
            reverseList(l,lk);
            l->next = r;
            if(t1 != nullptr) t1->next = lk;
            swap(l,lk);
            if(i==1) head = l;
            t1 = lk;
        }
        return head;
    }
};
