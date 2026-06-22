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
    void GotoEnd(ListNode*& itend) {
        while(itend->next != nullptr) {
            itend = itend->next;
        }
    }
    
    void GotoSecond(ListNode*& itsec,ListNode* head) {
        itsec=head;
        while(itsec->next!=nullptr && itsec->next->next != nullptr) {
            itsec = itsec->next;
        }
    }

    void reorderList(ListNode* head) {
        ListNode* it1 = head;
        //ListNode* it2 = head->next;
        ListNode* itend = it1;
        ListNode* itsec = it1;
        GotoEnd(itend);
        GotoSecond(itsec, head);
        while(it1->next != nullptr && it1->next->next != nullptr) {
            itend->next = it1->next;
            it1->next = itend;
            itsec->next = nullptr;
            GotoEnd(itend);
            GotoSecond(itsec, head);
            it1 = it1->next->next;
        }
    }
};
