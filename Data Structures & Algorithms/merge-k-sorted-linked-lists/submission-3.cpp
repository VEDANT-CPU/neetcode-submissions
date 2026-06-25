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
    ListNode* mergeTwoLists(ListNode*& l1, ListNode*& l2) {
        ListNode* new_list = new ListNode(-1);
        ListNode* temp = new_list;
        while(l1 != nullptr && l2 != nullptr) {
            if(l1->val < l2->val) {
                temp->next = l1;
                temp = temp->next;
                l1 = l1->next;
            }else {
                temp->next = l2;
                l2 = l2->next;
                temp = temp->next;
            }
        }
        while(l1 != nullptr) {
            temp->next = l1;
            l1 = l1->next;
            temp = temp->next;
        }
        while(l2 != nullptr) {
            temp->next = l2;
            l2 = l2->next;
            temp = temp->next;
        }
        temp = new_list->next;
        new_list->next = nullptr;
        return temp;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        ListNode* new_list = nullptr;
        if(k > 0) new_list = lists[0];
        else return new_list;
        //mergeTwoLists is O(n1 + n2) time.
        while(lists.size() > 1) {
            for(int i=0; i<lists.size(); i+=2) {
                if(i+1 < lists.size()) {
                    lists[i] = mergeTwoLists(lists[i],lists[i+1]);
                    //lists.erase(lists.begin()+i+1);
                }
            }
            for(int i=0; i<lists.size(); i+=1) {
                if(lists[i]==nullptr) {
                    lists.erase(lists.begin()+i);
                }
            }
        }
        new_list = lists[0];
        //thus running time is O(k * n)
        return new_list;
    }
};
