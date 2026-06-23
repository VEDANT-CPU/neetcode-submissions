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
        ListNode* t1=l1;
        ListNode* t2=l2;
        ListNode* new_list = nullptr;
        ListNode* temp = nullptr;
        int dig_sum=0;
        int dig_carry=0;
        while(t1!=nullptr && t2!=nullptr) {
            dig_sum = t1->val + t2->val;
            if(temp == nullptr) {
                new_list = new ListNode(dig_sum % 10);
                dig_sum /= 10;
                dig_carry = dig_sum%10;
                temp = new_list;
            }else {
                dig_sum += dig_carry;
                ListNode* new_node = new ListNode(dig_sum%10);
                dig_sum /= 10;
                dig_carry = dig_sum%10;
                temp->next = new_node;
                temp = temp->next;
            }
            t1 = t1->next;
            t2 = t2->next;
        }

        while(t1!=nullptr) {
            dig_sum = t1->val + dig_carry;
            ListNode* new_node = new ListNode(dig_sum%10);
            dig_sum /= 10;
            dig_carry = dig_sum%10;
            temp->next = new_node;
            temp = temp->next;
            t1 = t1->next;
        }
        while(t2!=nullptr) {
            dig_sum = t2->val + dig_carry;
            ListNode* new_node = new ListNode(dig_sum%10);
            dig_sum /= 10;
            dig_carry = dig_sum%10;
            temp->next = new_node;
            temp = temp->next;
            t2 = t2->next;
        }
        if(dig_carry!=0) {
            ListNode* new_node = new ListNode(dig_carry);
            temp->next = new_node;
            temp = temp->next;
        }
        return new_list;
    }
};
